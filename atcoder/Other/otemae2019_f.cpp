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
    int n, d;
    cin >> n >> d;
    vector<vector<ll>> v(d, vector<ll>(n+1, 0));
    vector<vector<ll>> dp(d+1, vector<ll>(n+1, INF<ll>));
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &v[i][j+1]);
            v[i][j+1] += v[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i+1][j] = dp[i][j] + abs(v[i][n]-2*v[i][j]);
        }
    }
    cout << *min_element(dp[d].begin(),dp[d].end()) << "\n";
    return 0;
}