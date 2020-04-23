#include <iostream>
#include <algorithm>
#include <vector>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    uint32_t A, B;
    cin >> A >> B;
    vector<int> v1(A+1, 0), v2(B+1, 0);
    vector<vector<int> > dp(A+2, vector<int> (B+2, 0));
    for (int i = 0; i < A; ++i) cin >> v1[i];
    for (int j = 0; j < B; ++j) cin >> v2[j];
    for (int i = A; i >= 0; --i) {
        for (int j = B; j >= 0; --j) {
            if(i+j == A + B) continue;
            if((i+j)%2 == 0){
                if (i == A)     dp[i][j] = dp[i][j+1]+v2[j];
                else if(j == B) dp[i][j] = dp[i+1][j]+v1[i];
                else            dp[i][j] = max(dp[i+1][j]+v1[i], dp[i][j+1]+v2[j]);
            }else{
                if (i == A)     dp[i][j] = dp[i][j+1];
                else if(j == B) dp[i][j] = dp[i+1][j];
                else            dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[0][0] << "\n";
    return 0;
}
