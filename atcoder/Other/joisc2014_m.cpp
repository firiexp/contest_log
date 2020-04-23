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

ll INF = 1000000000000000007LL;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(2*n+1, -INF));
    dp[0][n] = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        for (int j = 0; j <= 2*n; ++j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            int to = max(0LL, min(2*n, j+a));
            dp[i+1][to] = max(dp[i+1][to], dp[i][j]+b);
        }
    }
    ll ans = -INF;
    for (int i = n-1; i <= 2*n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << "\n";
    return 0;
}