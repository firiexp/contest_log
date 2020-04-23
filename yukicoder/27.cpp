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

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    array<ll, 31> dp{};
    ll ans = INF<int>;
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k = 1; k < j; ++k) {
                fill(dp.begin(),dp.end(), INF<int>);
                dp[0] = 0;
                for (int l = 1; l <= 30; ++l) {
                    if(i <= l) dp[l] = min(dp[l], dp[l-i]+1);
                    if(j <= l) dp[l] = min(dp[l], dp[l-j]+1);
                    if(k <= l) dp[l] = min(dp[l], dp[l-k]+1);
                }
                ans = min(ans, dp[a]+dp[b]+dp[c]+dp[d]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}