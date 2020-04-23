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
    u32 n, ma, mb;
    cin >> n >> ma >> mb;
    vector<vector<int>> dp(500, vector<int>(500, INF));
    dp[0][0] = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = x; j >= 0; --j) {
            for (int k = y; k >= 0; --k) {
                dp[j+a][k+b] = min(dp[j+a][k+b], dp[j][k]+c);
            }
        }
        x += a, y += b;
    }
    int ans = INF;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if(i*mb == j*ma) ans = min(ans, dp[i][j]);
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}
