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
    long double a, b, x, y;
    cin >> a >> b >> x >> y;
    long double l = 0, r = 1e9L;
    for (int i = 0; i < 300; ++i) {
        long double mid = (l+r)/2;
        if(a*mid > x || b*mid > y) r = mid;
        else l = mid;
    }
    cout << setprecision(20) << l*(a+b) << "\n";
    return 0;
}
