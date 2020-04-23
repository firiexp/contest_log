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
    explicit AhoCorasick() : v(1), dep(1) {}
    vector<Node> v;
    vector<int> dep;
    vector<int> ord;
    int add(string &s, int x = 0, int cur = 0){
        for (auto &&i : s) {
            if(!v[cur].to[i-start]) {
                v[cur].to[i-start] = v.size();
                v.emplace_back();
                dep.emplace_back(dep[cur]+1);
            }
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
    ll n, q, x, y;
    cin >> n >> q >> x >> y;
    AhoCorasick<26, 'a'> aho;
    vector<string> A(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        v[i] = aho.add(A[i]);
    }
    aho.build();
    vector<ll> dp(aho.v.size(), INF<ll>);
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        ll val = A[i].size()*y;
        for (int j = 0; j <= A[i].size(); ++j) {
            chmin(dp[cur], val);
            val -= x+y;
            if(j != A[i].size()) cur = aho.next(cur, A[i][j]);
        }
    }
    for (auto &&k : aho.ord) if(k) chmin(dp[k], dp[aho.v[k].fail]);
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        ll ans = INF<ll>;
        for (int j = 0; j <= s.size(); ++j) {
            chmin(ans, dp[cur]+x*(int)s.size());
            if(j != s.size()) cur = aho.next(cur, s[j]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}