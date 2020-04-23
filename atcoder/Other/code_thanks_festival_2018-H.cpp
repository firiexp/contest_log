#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    reverse(v.begin(), v.end());
    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + v[i];
    }
    ll ok = -INF<ll>, ng = INF<ll>;
    while(ng-ok > 1){
        ll mid = (ng+ok)/2;
        vector<int> dp1(n+1, -INF<int>), dp2(n+1, -INF<int>);
        dp1[0] = 0, dp2[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp1[i] = max(dp1[i], -dp2[j] + ((sum[i]-sum[j] >= mid) ? 1 : -1));
                dp2[i] = max(dp2[i], -dp1[j] + ((sum[i]-sum[j] < mid) ? 1 : -1));
            }
        }
        if(dp1[n] >= 0) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
