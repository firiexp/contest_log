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

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, t, l, b;
    while(cin >> n >> t >> l >> b, n){
        map<int, int> m;
        for (int i = 0; i < l; ++i) {
            int x;
            cin >> x;
            m[x] = 1;
        }
        for (int i = 0; i < b; ++i) {
            int x;
            cin >> x;
            m[x] = 2;
        }
        auto dp = make_v(t+2, n+1, 0.0L);
        dp[0][0] = 1;
        double ans = 0;
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    int to = min(n, j+k)-max(j+k-n, 0);
                    dp[i+1+(m[to] == 1)][to] += dp[i][j]/6;
                }
            }
            for (int j = 0; j < n; ++j) {
                if(m[j] == 2) {
                    dp[i+1][0] += dp[i+1][j];
                    dp[i+1][j] = 0;
                }
            }
        }
        for (int i = 0; i <= t; ++i) {
            ans += dp[i][n];
        }
        printf("%.6f\n", ans);
    }
    return 0;
}