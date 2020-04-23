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
    ll n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    ll ans = n;
    for (ll i = 0; i <= n; i += d) {
        if(n-i >= 0) ans = min(ans, (n-i)%e);
    }
    cout << ans << "\n";
    return 0;
}