#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
int c[200][3],dp[200][200];

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> t(200);
    for (int i = 0; i < d; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    fill_n(&dp[0][0], 40000, 0);
    {
        int i = t[0];
        for (int j = 0; j < n; ++j) {
            if(c[j][0] <= i && i <= c[j][1]){
                dp[j][0] = 1000000;
            }
        }
    }
    for (int i = 1; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
            if(c[j][0] <= t[i] && t[i] <= c[j][1]){
                for (int k = 0; k < n; ++k) {
                    if(dp[k][i-1]){
                        dp[j][i] = max(dp[k][i-1]+abs(c[j][2]-c[k][2]), dp[j][i]);
                    }
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if(dp[i][d-1] > max) max = dp[i][d-1];
    }
    cout << max-1000000 << "\n";
    return 0;
}
