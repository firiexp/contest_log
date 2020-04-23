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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> next(n);

    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        next[l] = max(next[l], r);
    }
    for (int i = 0; i < n; ++i) {
        next[i] = max(next[i], i+1);
        if(i) next[i] = max(next[i], next[i-1]);
    }
    vector<ll> dp(n+1, -INF<ll>);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = max(dp[i+1], dp[i]);
        dp[next[i]] = max(dp[next[i]], dp[i]+v[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}