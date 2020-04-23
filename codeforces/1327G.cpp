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
        int val;
    };
    explicit AhoCorasick() : v(1) {}
    vector<Node> v;
    vector<int> ord;
    int add(string &s, int cur = 0){
        for (auto &&i : s) {
            if(!v[cur].to[i-start]) v[cur].to[i-start] = v.size(), v.emplace_back();
            cur = v[cur].to[i-start];
        }
        return cur;
    }

    void build() {
        v[0].fail = -1;
        int l = 0, r = 1;
        ord.clear();
        ord.reserve(v.size());
        ord.emplace_back(0);
        while(l < r){
            int i = ord[l]; l++;
            for (int c = 0; c < W; ++c) {
                if(!v[i].to[c]) continue;
                int to = v[i].to[c];
                v[to].fail = (v[i].fail == -1 ? 0 : v[v[i].fail].to[c]);
                ord.emplace_back(to);
                r++;
            }
            if(i != 0){
                for (int c = 0; c < W; ++c) {
                    if(!v[i].to[c]) v[i].to[c] = v[v[i].fail].to[c];
                }
            }
        }
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
    int k;
    cin >> k;
    vector<string> a(k);
    vector<int> b(k), curs(k);
    AhoCorasick<14, 'a'> aho;
    for (int i = 0; i < k; ++i) {
        cin >> a[i] >> b[i];
        curs[i] = aho.add(a[i]);
    }
    aho.build();
    vector<int> dp(aho.v.size());
    for (int i = 0; i < k; ++i) {
        dp[curs[i]] += b[i];
    }
    for (auto &&i : aho.ord) {
        if(i) dp[i] += dp[aho.v[i].fail];
    }
    string s;
    cin >> s;
    vector<int> question;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '?') question.emplace_back(i);
    }
    auto nxt = make_v(question.size()+1, aho.v.size(), 0);
    auto score = make_v(question.size()+1, aho.v.size(), 0LL);
    for (auto &&i : nxt) {
        iota(i.begin(),i.end(), 0);
    }
    int cur = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if(s[i] == '?'){
            cur++;
            continue;
        }
        for (int j = 0; j < aho.v.size(); ++j) {
            nxt[cur][j] = aho.next(nxt[cur][j], s[i]);
            score[cur][j] += dp[nxt[cur][j]];
        }
    }
    auto ans = make_v(1 << 14, aho.v.size(), -INF<ll>);
    ans[0][nxt[0][0]] = score[0][0];
    ll finalans = -INF<ll>;
    for (int i = 0; i < (1 << 14); ++i) {
        int x = __builtin_popcount(i)+1;
        if(x > cur+1) continue;
        if(x == cur+1) {
            chmax(finalans, *max_element(ans[i].begin(),ans[i].end()));
            continue;
        }
        for (int j = 0; j < 14; ++j) {
            if(i & (1 << j)) continue;
            for (int l = 0; l < aho.v.size(); ++l) {
                if(ans[i][l] == -INF<ll>) continue;
                ll val = ans[i][l];
                int ii = i | (1 << j);
                int l2 = aho.next(l, 'a'+j);
                val += dp[l2];
                val += score[x][l2];
                l2 = nxt[x][l2];
                chmax(ans[ii][l2], val);
            }
        }
    }
    cout << finalans << "\n";
    return 0;
}