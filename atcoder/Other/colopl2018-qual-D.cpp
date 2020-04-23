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
    int n, x;
    cin >> n >> x;
    vector<int> v(n), to(n);
    for (auto &&i : v) scanf("%d", &i);

    for (int i = 0; i < n; ++i) {
        to[i] = static_cast<int>(upper_bound(v.begin(), v.end(), v[i] + x) - v.begin()-1);
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[to[i]][j+1] = max(dp[to[i]][j+1], dp[i][j]+min(v[to[i]]-v[i],x));
            if(to[i]+1 < n) dp[to[i]+1][j+1] = max(dp[i][j]+min(v[to[i]+1]-v[i], x), dp[to[i]+1][j+1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = max(ans, dp[j][i]);
        }
        cout << ans+x << "\n";
    }
    return 0;
}
