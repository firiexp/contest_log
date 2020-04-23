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
    sort(v.begin(),v.end());
    vector<ll> dp(n, INF<ll>);
    dp[1] = v[1]-v[0];
    if(n > 2) dp[2] = v[2]-v[0];
    for (int i = 3; i < n; ++i) {
        dp[i] = min(dp[i], dp[i-2]+v[i]-v[i-1]);
        dp[i] = min(dp[i], dp[i-3]+v[i]-v[i-2]);
    }
    cout << dp.back() << "\n";
    return 0;
}