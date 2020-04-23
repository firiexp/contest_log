#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1), dq(n+1);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if(s[j] == 'W') dp[j]++;
            else dq[j+1]++;
        }
    }
    for (int i = 1; i <= n; ++i) dq[i] += dq[i-1];
    for (int i = n-1; i >= 0; --i) dp[i] += dp[i+1];
    int M = dp[0]+dq[0], ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(dp[i]+dq[i] < M){
            M = dp[i]+dq[i];
            ans = i;
        }
    }
    cout << ans << " " << ans+1 << "\n";
    return 0;
}