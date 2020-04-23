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

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

double pi = acos(-1);
int main() {
    double a, b;
    cin >> a >> b;
    double aa = acos(1-2*(a*a/b/b));
    printf("%.10lf\n", 2*pi-aa);
    printf("%.10lf\n", 4*a*b*(pi-aa/2)+pi*a*a);
    return 0;
}