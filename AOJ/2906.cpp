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
    int c, n, m;
    cin >> c >> n >> m;
    vector<ll> dp(c+1, -INF<ll>);
    dp[0] = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    for (int j = 0; j < n; ++j) {
        for (int i = c; i >= v[j].first; --i) {
            dp[i] = max(dp[i], dp[i-v[j].first]+v[j].second);
        }
    }
    for (int i = 0; i < c; ++i) {
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    for (int i = 1; i <= m; ++i) {
        cout << dp[c/i]*i << "\n";
    }
    return 0;
}