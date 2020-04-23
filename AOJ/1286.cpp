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
    int n, m, x;
    while(cin >> n >> m >> x, n){
        vector<vector<double>> dp(2, vector<double>(n*m+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int now = i&1, nxt = now^1;
            fill(dp[nxt].begin(),dp[nxt].end(), 0);
            for (int j = 0; j <= m*i; ++j) {
                for (int k = 1; k <= m; ++k) {
                    dp[nxt][j+k] += dp[now][j]/m;
                }
            }
        }
        double ans = 0;
        for (int i = 0; i <= n*m; ++i) {
            ans += dp[n&1][i]*max(i-x, 1);
        }
        printf("%.8f\n", ans);
    }
    return 0;
}