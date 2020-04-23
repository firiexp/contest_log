#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> T(n), V(n);
    for (int i = 0; i < n; ++i) cin >> T[i];
    for (int j = 0; j < n; ++j) cin >> V[j];
    vector<vector<double>> dp(105, vector<double>(120, 0.0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= V[i]; ++j) {
            if(dp[i][j]){
                for (int k = 0; k <= V[i]; ++k) {
                    int a = V[i] - j;
                    int b = V[i] - k;
                    if (a + b <= T[i]) {
                        dp[i + 1][k] = max(dp[i + 1][k],
                                dp[i][j] + 1.0*(j+V[i])*a/2 + V[i] * (T[i]-a-b) + 1.0 * (k+V[i])* b / 2);
                    } else if (T[i] < abs(k - j)) {
                    } else {
                        double x = 1.0 * (k - j + T[i]) / 2;
                        double y = 1.0 * (T[i] - k + j) / 2;
                        double vvv = j + x;
                        dp[i + 1][k] = max(dp[i + 1][k],
                                dp[i][j] + 1.0*(j+vvv)*x/2+1.0*(k+vvv)*y/2);
                    }
                }
            }
        }
    }
    printf("%.10f\n", dp[n][0] - 1);
    return 0;
}
