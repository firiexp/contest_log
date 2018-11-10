#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s, t = "yahoo";
    cin >> s;
    vector<vector<int>> dp(s.length()+1, vector<int>(5, INF<int>));
    dp[0][0] = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 25; ++j) {
            dp[i][(j+1)%5] = min(dp[i][(j+1)%5], dp[i][j%5] + 1);
            dp[i+1][j%5] = min(dp[i+1][j%5], dp[i][j%5]+1);
            if(s[i] == t[j%5]) dp[i+1][(j+1)%5] = min(dp[i][j%5], dp[i+1][(j+1)%5]);
            else dp[i+1][(j+1)%5] = min(dp[i][j%5]+1, dp[i+1][(j+1)%5]);
        }
    }
    cout << dp[s.length()][0] << "\n";
    return 0;
}
