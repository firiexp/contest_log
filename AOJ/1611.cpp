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

int dp[302][302];
int main() {
    int n;
    while(cin >> n, n){
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -INF<int>;
            }
            dp[i][i] = 0;
        }
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i+len <= n; ++i) {
                int j = i+len;
                if(abs(v[j-1]-v[i]) <= 1){
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
                }
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][i+1] = 0;
        }
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i+len <= n; ++i) {
                int j = i+len;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}