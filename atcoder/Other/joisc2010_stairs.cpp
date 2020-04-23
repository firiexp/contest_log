#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1234567;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> v(n+1);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[i+1] = v[i] + x;
    }
    vector<int> dp(n+1), dpsum(n+2);
    dp[0] = dpsum[1] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i+1] =(dpsum[i+1]
                - dpsum[lower_bound(v.begin(), v.end(), v[i+1]-p) - v.begin()]+MOD) % MOD;
        dpsum[i+2] = (dpsum[i+1] + dp[i+1]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}
