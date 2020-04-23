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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int dp[2][21][1048576];

int main() {
    int n, m, c, d;
    cin >> n >> m >> c >> d;
    auto v = make_v(n, n, 0);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x-1][y-1] = 1;
    }
    fill(dp[0][0], dp[1][21], INF<int>);
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    for (int i = 1; i < (1<<n); ++i) {
        int pc = __builtin_popcount(i);
        for (int j = 0; j < n; ++j) {
            if((i & (1 << j)) == 0) continue;
            int p = i ^ (1<<j);
            int valid = true;
            for (int k = 0; k < n; ++k) {
                if(v[k][j] && (i & (1 << k)) == 0) {
                    valid = false;
                    break;
                }
            }
            if(!valid) continue;
            for (int k = 0; k < pc; ++k) {
                chmin(dp[0][k][i], dp[0][k][p]+a[j]);
                chmin(dp[0][k+1][i], dp[1][k][p]+a[j]);
                chmin(dp[1][k+1][i], dp[0][k][p]+b[j]);
                chmin(dp[1][k][i], dp[1][k][p]+b[j]);
            }
        }
    }
    int ans = INF<int>, x = 0;
    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i < 2; ++i) {
            chmin(ans, dp[i][j][(1<<n)-1]+x);
        }
        x += c*j+d;
    }
    cout << ans << "\n";
    return 0;
}
