#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n+1), dp2(n+1);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i]+(s[i] == '#');
    }
    for (int j = n-1; j >= 0; --j) {
        dp2[j] = dp2[j+1]+(s[j] == '.');
    }
    int ans = INF<int>;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, dp[i]+dp2[i]);
    }
    cout << ans << "\n";
    return 0;
}
