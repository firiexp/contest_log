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

long double f(long double x, long double P){
    return x + P*pow(2.0L, -x/1.5);
}


int main() {
    long double p;
    cin >> p;
    long double l = 0.0, r = INF<float>;
    for (int i = 0; i < 1100; ++i) {
        if(f((l*2+r)/3, p) > f((l+r*2)/3, p)){
            l = (l*2+r)/3;
        }else {
            r = (r*2+l)/3;
        }
    }
    cout << setprecision(20) << (f(l, p)+f(r, p))/2 << "\n";
    return 0;
}
