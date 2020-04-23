#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;
    ll ans = INF<ll>;
    for (int i = 0; i <= n; ++i) {
        ll k = (n-i)*e-h-b*i;
        ll j = k < 0 ? 0 : k/(d+e)+1;
        ans = min(ans, a*i+c*j);
    }
    cout << ans << "\n";
    return 0;
}
