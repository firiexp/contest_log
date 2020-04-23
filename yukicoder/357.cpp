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
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int s, t, u;
        scanf("%d %d %d", &s, &t, &u);
        v[s][t] = u;
    }
    vector<int> dp(1<<n, -INF<int>);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(!(i & (1 << j))) continue;
            int x = 0;
            for (int k = 0; k < n; ++k) {
                if(!(i & (1 << k))) continue;
                x += v[k][j];
            }
            dp[i] = max(dp[i], dp[i ^ (1 << j)]+x);
        }
    }
    cout << dp.back() << "\n";
    return 0;
}