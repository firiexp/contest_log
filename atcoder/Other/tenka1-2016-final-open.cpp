#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<int W, class F> // W -> word size
struct Trie {
    struct Node {
        char c;
        vector<int> nxt, idxs;
        int id;
        explicit Node(char c): c(c), nxt(W, -1), id(-1){}
    };
    vector<Node> v;
    F f;
    explicit Trie(F f, char c = '$') : f(f) {
        v.emplace_back(c);
    }
    void add(const string &s, int x){
        int cur = 0;
        for (auto &&i : s) {
            int k = f(i);
            if(~v[cur].nxt[k]){
                cur = v[cur].nxt[k];
                continue;
            }
            int npos = v.size();
            v[cur].nxt[k] = npos;
            v.emplace_back(i);
            cur =  npos;
        }
        v[cur].id = x;
        v[cur].idxs.emplace_back(x);
    }

    int find(const string &s){
        int cur = 0;
        for (auto &&i : s) {
            int k = f(i);
            if(v[cur].nxt[k] < 0) return -1;
            cur = v[cur].nxt[k];
        }
        return cur;
    }
    int find(int cur, char c) {return v[cur].nxt[f(c)]; }
    int id(int cur) { return cur < 0 ? -1 : v[cur].id;}

    vector<int> idxs(int cur) { return cur < 0 ? vector<int>() : v[cur].idxs; }
};

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    auto f = [](char c){ return c-'a';};
    Trie<26, decltype(f)> trie(f);
    string s; int m;
    cin >> s >> m;
    vector<string> v(m);
    for (auto &&i : v) {
        cin >> i;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        trie.add(v[i], x);
    }
    int ans = 0;
    int n = s.size();
    vector<int> dp(n+1);
    for (int i = 0; i < n; ++i) {
        chmax(ans, dp[i]);
        int cur = 0;
        for (int j = 0; i+j < n && j <= 200; ++j) {
            cur = trie.find(cur, s[i+j]);
            if(cur == -1) break;
            int val = trie.id(cur);
            if(val > 0) chmax(dp[i+j+1], ans+val);
        }
    }
    chmax(ans, dp[n]);
    cout << ans << "\n";
    return 0;
}
