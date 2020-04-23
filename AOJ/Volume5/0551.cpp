#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = make_pair(v[i], i);
    }
    sort(a.begin(), a.end(), greater<>());
    vector<ll> dp(n+2);
    ll ans = 0;
    for (int q = 0; q < n; ++q) {
        int i = a[q].second;
        dp[i+1] = max(dp[i], dp[i+2])+ l-v[i];
        ans = max(ans, dp[i+1]);
    }
    cout << ans << "\n";
    return 0;
}
