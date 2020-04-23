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

template <class T>
T pow_ (T x, T n, int M){
    x %= M;
    if(x == 0) return 0;
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    ll a, b, c;
    scanf("%lld^%lld^%lld", &a, &b, &c);
    if(a%MOD == 0) {
        puts("0 0");
        return 0;
    }
    cout << pow_(pow_(a%MOD, b, MOD), c, MOD) << " ";
    cout << pow_(a%MOD, pow_(b%(MOD-1), c, MOD-1), MOD) << "\n";
    return 0;
}