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
    long double c, r1, r2;
    cin >> c >> r1 >> r2;
    long double a = (r2-r1)/2, b = (r2+r1)/2;
    cout << setprecision(20) << acos(-1)*acos(-1)*c*a*a*b*2 << "\n";
    return 0;
}
