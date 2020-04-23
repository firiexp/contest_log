#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<int W, int start>
class AhoCorasick {
public:
    struct Node {
        array<int, W> to;
        int fail;
    };
    explicit AhoCorasick() : v(1) {}
    vector<Node> v;

    int add(string &s, int cur = 0){
        for (auto &&i : s) {
            if(!v[cur].to[i-start]) v[cur].to[i-start] = v.size(), v.emplace_back();
            cur = v[cur].to[i-start];
        }
        return cur;
    }

    void build() {
        v[0].fail = -1;
        queue<int> Q; Q.emplace(0);
        while(!Q.empty()){
            int i = Q.front(); Q.pop();
            for (int c = 0; c < W; ++c) {
                if(!v[i].to[c]) continue;
                int to = v[i].to[c];
                v[to].fail = (v[i].fail == -1 ? 0 : v[v[i].fail].to[c]);
                Q.emplace(to);
            }
            if(i != 0){
                for (int c = 0; c < W; ++c) {
                    if(!v[i].to[c]) v[i].to[c] = v[v[i].fail].to[c];
                }
            }
        }
        v[0].fail = 0;
    }
    inline int next(int x, char c){ return v[x].to[c-start]; }
};

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    string s, a, b;
    cin >> s >> a >> b;
    AhoCorasick<26, 'a'> aho;

    int acur = aho.add(a), bcur = aho.add(b);
    aho.build();
    int n = s.size(), m = aho.v.size();
    vector<int> val(m);
    val[acur]++; val[bcur]--;
    for (int i = 1; i < m; ++i) {
        val[i] += val[aho.v[i].fail];
    }
    auto dp = make_v(n+1, m, -INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(dp[i][j] == -INF<int>) continue;
            char l = s[i],r = s[i];
            if(s[i] == '*') l = 'a', r = 'z';
            for (char c = l; c <= r; ++c) {
                auto nxt = aho.next(j, c);
                chmax(dp[i+1][nxt], dp[i][j] + val[nxt]);
            }
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}