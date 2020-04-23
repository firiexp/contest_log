#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 10000;
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
    int n, k;
    cin >> n >> k;
    vector<int> menu(n, 0);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        menu[a-1] = b;
    }
    auto dp = make_v(n+1, 4, 4, 0);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if(menu[i-1]){
            for (int j = 0; j < 4; ++j) {
                for (int l = 0; l < 4; ++l) {
                    if(j == menu[i-1] && j == l) continue;
                    (dp[i][j][menu[i-1]] += dp[i-1][l][j]) %= MOD;
                }
            }
        }else {
            for (int m = 1; m < 4; ++m) {
                for (int j = 0; j < 4; ++j) {
                    for (int l = 0; l < 4; ++l) {
                        if(j == m && j == l) continue;
                        (dp[i][j][m] += dp[i-1][l][j]) %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            (ans += dp[n][i][j]) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
