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
#include <cmath>
static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

const auto pi = acos(-1);

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double ok = 0, ng = 90;
    for (int i = 0; i < 100; ++i) {
        auto mid = (ok+ng)/2, m = (mid)/180*pi;
        if(a*sin(m) <= b*sin((90-mid)/180*pi)){
            (x <= a*a*a*tan(m)/2+(b*cos(m)-a*sin(m))*a*a/cos(m) ? ok : ng) = mid;
        }else {
            (x <= a*b*b/2/tan(m) ? ok : ng) = mid;
        }
    }
    printf("%.10lf\n", ok);
    return 0;
}