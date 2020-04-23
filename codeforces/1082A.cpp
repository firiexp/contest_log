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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        ll ans = INF<ll>;
        if((y-x)%d == 0) ans = min(ans, llabs(y-x)/d);
        if((y-1)%d == 0) ans = min(ans, (x-1+d-1)/d+(y-1)/d);
        if((n-y)%d == 0) ans = min(ans, (n-x+d-1)/d+(n-y)/d);
        cout << (ans == INF<ll> ? -1 : ans) << "\n";
    }
    return 0;
}
