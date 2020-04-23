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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> x(m), p(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x[i], &p[i]);
    }
    vector<long double> binom(n+1, 1);
    for (int i = 0; i < n; ++i) {
        binom[i+1] = binom[i]*(n-i)/(i+1);
    }
    auto dp = make_v(n+1, m+1, 0.0L);
    for (int i = n; i >= 0; --i) {
        long double s = 0;
        for (int j = 0; j <= m; ++j) {
            if(j) s += 1.0L*p[j-1]/q;
            dp[i][j] = binom[i]*pow(s, i)*pow(1-s, n-i);
            if(i != n) dp[i][j] += dp[i+1][j];
        }
    }
    long double ans = 0;
    for (int i = 1; i <= n; ++i) {
        long double l = -1;
        for (int j = 0; j < m; ++j) {
            l += 2*(dp[i][j+1]-dp[i][j]);
            if(l >= 0){
                for (int k = 0; k < m; ++k) {
                    ans += abs(x[k]-x[j])*(dp[i][k+1]-dp[i][k]);
                }
                break;
            }
        }
    }
    printf("%.15Lf\n", ans);
    return 0;
}