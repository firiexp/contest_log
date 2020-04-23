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
    vector<int> a(m), b(m), c(m);
    vector<ll> dp(1<<n, INF<ll>);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        int val = 0;
        for (int j = 0; j < b[i]; ++j) {
            int x;
            scanf("%d", &x);
            val += (1 << (x-1));
        }
        dp[val] = min(dp[val], (ll)a[i]);
    }
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = i&(i-1); j != i; j = i&(j-1)) {
            dp[j] = min(dp[j], dp[i]);
        }
    }
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = i&(i-1); j != i; j = i&(j-1)) {
            dp[i] = min(dp[i], dp[j]+dp[i^j]);
        }
    }
    cout << (dp.back() >= INF<ll> ? -1 : dp.back()) << "\n";
    return 0;
}