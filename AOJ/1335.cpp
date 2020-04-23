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
    int n, k, s;
    while(cin >> n >> k >> s, n){
        auto dp = make_v(k+1, 300, n+1, 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 220; ++j) {
                for (int l = 0; l <= n; ++l) {
                    for (int m = l+1; m <= n; ++m) {
                        dp[i+1][j+m][m] += dp[i][j][l];
                    }
                }
            }
        }
        int ans = 0;
        for (int l = 1; l <= n; ++l) {
            ans += dp[k][s][l];
        }
        cout << ans << "\n";
    }
    return 0;
}