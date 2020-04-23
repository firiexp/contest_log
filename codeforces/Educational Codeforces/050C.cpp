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
ll dp[20][2][4];

ll solve(string k){
    fill_n(dp[0][0], 160, 0LL);
    dp[0][0][0] = 1;
    for (int i = 0; i < k.size(); ++i) {
        const int D = k[i]-'0';

        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l < 4; ++l) {
                for (int m = 0; m <= (j ? 9 : D); ++m) {
                    if(m != 0 && l == 3) continue;
                    dp[i+1][j || (m < D)][(m != 0 ? l+1 : l)] += dp[i][j][l];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 3; ++i) {
        ans += dp[k.size()][0][i] + dp[k.size()][1][i];
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll l, r;
        cin >> l >> r;
        cout << solve(to_string(r)) - solve(to_string(l-1)) << "\n";
    }
    return 0;
}
