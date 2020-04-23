#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    long double a, b, c, l = -1, r = 1000;
    cin >> a >> b >> c;
    const long double pi = acos(-1.0);
    while((r > l ? r-l : l-r ) > 1e-12){
        auto mid = (l + r)/2;
        if(a*mid + b * sin(c*pi*mid) >= 100){
            r = mid;
        }else l = mid;
    };
    cout << setprecision(15) << l << "\n";
    return 0;
}
