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
    auto dp = make_v(n, 21, 0LL);
    dp[0][0] = 1;
    for (int i = 0; i < n-1; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j <= 20; ++j) {
            if(i && 0 <= j-k && j-k <= 20) dp[i+1][j-k] += dp[i][j];
            if(0 <= j+k && j+k <= 20) dp[i+1][j+k] += dp[i][j];
        }
    }
    int k;
    cin >> k;
    cout << dp[n-1][k] << "\n";
    return 0;

}
