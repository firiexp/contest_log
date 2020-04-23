#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n;
    cin >> n;
    vector<ll> x(n), c(n), v(n);
    for (auto &&i : x) scanf("%lld", &i);
    for (auto &&i : c) scanf("%lld", &i);
    for (auto &&i : v) scanf("%lld", &i);
    auto dp1 = make_v(n+1, 1<<n, 0LL);
    vector<ll> dp2(1<<n);
    vector<vector<int>> pc(n+1);
    for (int i = 0; i < (1 << n); ++i) {
        pc[__builtin_popcount(i)].emplace_back(i);
    }
    ll co = 0;
    for (int k = 0; k < n; ++k) {
        co += x[k];
        for (int p = 1; p <= n; ++p) {
            for (auto &&i : pc[p]) {
                ll mv = 0, mc = 0;
                for (int j = 0; j < n; ++j) {
                    if (i & (1<<j)) mv += v[j], mc += c[j];
                }
                if(co >= mc){
                    dp1[k+1][i] = mv;
                }else {
                    for (int j = 0; j < n; ++j) {
                        if (i & (1<<j)) dp1[k+1][i] = max(dp1[k+1][i], dp1[k+1][i-(1<<j)]);
                    }
                }
            }
        }
    }
    for (int p = 1; p <= n; ++p) {
        for (auto &&i : pc[p]) {
            ll w = INF<ll>;
            for (int j = 0; j < n; ++j) {
                if(i & (1<<j)){
                    w = min(w, dp2[i-(1<<j)]);
                }
            }
            dp2[i] = max(w, dp1[n-p][i]);

        }
    }
    cout << dp2[(1<<n)-1] << "\n";
    return 0;
}
