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
    cin >> n;
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        ans = max(ans, e*110/900+a+b+c+d);
    }
    cout << setprecision(20) << ans << "\n";
    return 0;
}
