#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v1(n+1, 0), v2(m+1, 0);
    for (int i = 1; i <= n; ++i) scanf("%lld", &v1[i]);
    for (int i = 1; i <= m; ++i) scanf("%lld", &v2[i]);
    int x;
    cin >> x;
    partial_sum(v1.begin(), v1.end(), v1.begin());
    partial_sum(v2.begin(), v2.end(), v2.begin());
    vector<ll> lm1(n+1, INF<int>), lm2(m+1, INF<int>);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            lm1[j - i] = min(lm1[j - i], v1[j] - v1[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            lm2[j - i] = min(lm2[j - i], v2[j] - v2[i]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(lm1[i]*lm2[j] <= x) ans = max(ans, (ll)i*j);
            else break;
        }
    }
    cout << ans << "\n";
    return 0;
}
