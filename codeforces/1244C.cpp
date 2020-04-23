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

template<typename T>
T extgcd(T a, T b, T &x ,T &y){
    for (T u = y = 1, v = x = 0; a; ) {
        ll q = b/a;
        swap(x -= q*u, u);
        swap(y -= q*v, v);
        swap(b -= q*a, a);
    }
    return b;
}

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll k = __gcd(w, __gcd(d, p));
    w /= k; d /= k; p /= k;
    ll x, y;
    extgcd(w, d, x, y);
    x *= p; y *= p;
    cout << x << " " << y << "\n";
    return 0;
}