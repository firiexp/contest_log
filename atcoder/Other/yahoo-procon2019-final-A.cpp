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
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

long double f(long double x, long double  a){
    long double p = min(a, x-a);
    return (p*2/3+(x-2*p))*p*p/(x-a)/(x-a);
}

int main() {
    long double h, w, a, b;
    cin >> h >> w >> a >> b;
    cout << setprecision(15) <<  f(h, a)*f(w, b) << "\n";
    return 0;
}
