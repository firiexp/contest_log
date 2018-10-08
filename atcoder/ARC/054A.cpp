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
    long double l, x, y, s, d, ans = 1e100;
    cin >> l >> x >> y >> s >> d;
    if(s > d) d += l;
    if(x < y) ans = min(ans, (l+s-d)/(y-x));
    ans = min(ans, (d-s)/(x+y));
    cout << setprecision(20) << ans << "\n";
    return 0;
}
