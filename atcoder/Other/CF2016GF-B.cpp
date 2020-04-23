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
    long double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long double ma = max({hypot(x2-x1, y2-y1), hypot(x3-x2, y3-y2),hypot(x3-x1,y3-y1)});
    long double S = fabs((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1))/2.0;
    long double r = 2*S/(hypot(x2-x1, y2-y1)+hypot(x3-x2, y3-y2)+hypot(x3-x1,y3-y1));
    cout << setprecision(20) << r*ma/(2*r+ma) << "\n";
    return 0;
}
