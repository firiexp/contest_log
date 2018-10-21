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
    ll a, b, c;
    cin >> a >> b >> c;
    a *= 60, c *= 3600;
    ll ans = (c+a-b-1)/(a-b);
    if(a < b) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
