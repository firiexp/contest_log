#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

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
    string k;
    int d;
    cin >> k >> d;
    auto dp = make_v(k.size()+1, 2, d, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < k.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            int x =  j ? 9 : k[i] - '0';
            for (int l = 0; l < d; ++l) {
                for (int m = 0; m <= x; ++m) {
                    (dp[i+1][j || m < x][(l+m)%d] += dp[i][j][l]) %= MOD;
                }
            }
        }
    }
    int ans = MOD-1;
    for (int j = 0; j < 2; ++j) {
        (ans += dp[k.size()][j][0]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
