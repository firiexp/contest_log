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
    ll n, x;
    cin >> n >> x;
    ll ans = n, a = n-x, b = x;
    if (a < b) swap(a, b);
    while (b > 0){
        ans += (2*(a/b))*b;
        ll c = a % b;
        a = b;
        b = c;
    }
    ans -= a;
    cout << ans << "\n";
    return 0;
}
