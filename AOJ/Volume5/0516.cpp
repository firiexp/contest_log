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
    int n, k;
    while(cin >> n >> k, n|k){
        vector<ll> v(n+1, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &v[i+1]);
        }
        partial_sum(v.begin(), v.end(), v.begin());
        ll ans = -INF<ll>;
        for (int i = 0; i < n-k+1; ++i) {
            ans = max(ans, v[i+k]-v[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
