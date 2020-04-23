#include <iostream>
#include <algorithm>
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

int main() {
    double a, b, c, d;
    double pi = 180/acos(-1.0);
    while(cin >> a >> b >> c >> d, b > -0.1){
        a /= pi; b /= pi; c /= pi; d /= pi;
        printf("%.0lf\n", 6378.1*acos(sin(a)*sin(c)+cos(a)*cos(c)*cos(d-b)));
    }
    return 0;
}