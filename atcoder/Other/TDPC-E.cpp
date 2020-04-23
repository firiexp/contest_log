#include <iostream>
using ll = long long;
using namespace std;
const int MOD = 1000000007;

int main() {
    int d;
    string n;
    cin >> d >> n;
    int dp[2][2][100];
    fill_n(&dp[0][0][0], 400, 0);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n.length(); ++i) {
        int x = n[i-1]-'0';
        fill_n(&dp[i%2][0][0], 200, 0);
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < d; ++k) {
                int m = (j ? 9 : x);
                for (int l = 0; l <= m; ++l) {
                    (dp[i%2][j|| l < m][(l + k) % d] += dp[(i+1)%2][j][k])
                                                     %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        (ans += dp[n.length()%2][i][0]) %= MOD;
    }
    cout << ans-1 << "\n";
    return 0;
}
