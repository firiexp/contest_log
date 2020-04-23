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
using ll = int64_t;
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
    int n;
    cin >> n;
    auto dp = make_v(n+1, 5, 5, 5, 5, 0);
    dp[0][0][0][0][0] = 1;
    auto dis = make_v(5, 5, 5, 5, 1);
    for (int i = 0; i <= 4; ++i) {
        dis[i][1][3][2] = 0;
        dis[i][3][1][2] = 0;
        dis[i][1][2][3] = 0;
        dis[1][i][3][2] = 0;
        dis[1][3][i][2] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                for (int l = 0; l < 5; ++l) {
                    for (int m = 0; m < 5; ++m) {
                        for (int x = 1; x < 5; ++x) {
                            if(dis[k][l][m][x]){
                                (dp[i+1][k][l][m][x] += dp[i][j][k][l][m]) %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 5; ++k) {
            for (int l = 0; l < 5; ++l) {
                for (int m = 0; m < 5; ++m) {
                    (ans += dp[n][j][k][l][m]) %= MOD;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
