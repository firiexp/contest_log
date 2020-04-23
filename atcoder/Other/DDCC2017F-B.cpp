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
    int n;
    ll z, ans = 1;
    cin >> n >> z;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ans = static_cast<ll>((__uint128_t)ans * __gcd(a, z) / __gcd(ans, __gcd(a, z)));
    }
    cout << ans << "\n";
    return 0;
}
