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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    c = min({a*4, b*2, c});
    int n;
    cin >> n;
    ll ans = (ll)n/2*min(c*2, d) + (n%2)*c;
    cout << ans << "\n";
    return 0;
}
