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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<ll> dp(n), dq(n);
    dp[0] = v[0], dq[0] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max({dp[i-1]+v[i], dq[i-1]+v[i],
                       dp[i-1]-v[i], dq[i-1]-v[i],
                       dp[i-1]*v[i], dq[i-1]*v[i]});
        dq[i] = min({dp[i-1]+v[i], dq[i-1]+v[i],
                       dp[i-1]-v[i], dq[i-1]-v[i],
                       dp[i-1]*v[i], dq[i-1]*v[i]});
        if(v[i]) {
            dp[i] = max({dp[i], dp[i-1]/v[i], dq[i-1]/v[i]});
            dq[i] = min({dq[i], dp[i-1]/v[i], dq[i-1]/v[i]});
        }
    }
    cout << dp.back() << "\n";
    return 0;
}