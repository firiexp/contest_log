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
    vector<int> a(n);
    for (auto &&i : a) scanf("%d", &i);
    auto dp = make_v(n+1, n+1, 0LL);
    // dp[i][j] 区間[i, j)が残ったときのスコア
    for (int x = 1; x <= n; ++x) {
        for (int i = 0; i < n; ++i) {
            int j = i+x;
            if(j > n) break;
            if((n-x)%2 == 0){
                dp[i][j] = -INF<ll>;
                if(i+1 < n) dp[i][j] = max(dp[i][j], dp[i+1][j]+a[i]);
                if(j >= 1) dp[i][j] = max(dp[i][j], dp[i][j-1]+a[j-1]);
            }else {
                dp[i][j] = INF<ll>;
                if(i+1 < n) dp[i][j] = min(dp[i][j], dp[i+1][j]-a[i]);
                if(j >= 1) dp[i][j] = min(dp[i][j], dp[i][j-1]-a[j-1]);
            }
        }
    }
    cout << dp[0][n] << "\n";
    return 0;
}
