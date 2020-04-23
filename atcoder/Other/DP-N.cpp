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
    int n;
    cin >> n;
    auto dp = make_v(n, n, INF<ll>/100);
    vector<ll> S(n+1);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        s += k;
        S[i+1] = s;
        dp[i][i] = 0;
    }
    for (int j = 1; j <= n; ++j) {
        for (int l = 0; l < n; ++l) {
            int r = l+j;
            if(r >= n) continue;
            for (int mid = l; mid < r; ++mid) {
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid+1][r] + S[r+1]-S[l]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}
