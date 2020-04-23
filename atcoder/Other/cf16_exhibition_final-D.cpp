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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<long double> p(6), q(6);
    for (int i = 0; i < 6; ++i) {
        cin >> p[i];
        p[i] /= 100;
    }
    for (int i = 0; i < 6; ++i) {
        cin >> q[i];
        q[i] /= 100;
    }
    long double l = 0, r = 1;
    long double a = 0, b = 0;
    for (int i = 0; i < 100; ++i) {
        long double x = (l*2+r)/3, y = (l+2*r)/3;
        a = 0, b = 0;
        for (int j = 0; j < 6; ++j) {
            a += max(x*p[j], (1-x)*q[j]);
            b += max(y*p[j], (1-y)*q[j]);
        }
        if(a < b) r = y;
        else l = x;
    }
    printf("%.15Lf", min(a, b));
    return 0;
}