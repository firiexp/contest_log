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
    int t ,a, b, c, d, ans = 0;
    cin >> t >> a >> b >> c >> d;
    if(a+c <= t) ans = max(ans, b+d);
    if(a <= t) ans = max(ans, b);
    if(c <= t) ans = max(ans, d);
    cout << ans << "\n";
    return 0;
}
