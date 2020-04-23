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
    int n, p, q;
    cin >> n >> p >> q;
    if((p+q)&1) {
        puts("0");
        return 0;
    }
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);

    vector<ll> dp(n+1), dq(n+1);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i] + (v[i] == (p+q)/2);
    }
    map<int, int> m;
    for (int i = n-1; i >= 0; --i) {
        dq[i] = m[v[i]];
        m[-v[i]+(p-q)/2]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i]*dq[i];
    }
    cout << ans << "\n";
    return 0;
}