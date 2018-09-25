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
    vector<int> v = {
            1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049
    };
    u32 n;
    cin >> n;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto &&x : v) {
            if(i-x >= 0){
                dp[i] = min(dp[i-x]+1, dp[i]);
            }else break;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
