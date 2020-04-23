#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

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

template<typename T>
T mod_inv(T x, T m){
    T s, t;
    extgcd(x, m, s, t);
    return (m+s)% m;
}


int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll p = a*b%MOD, q = b*c%MOD, r = c*a%MOD;
    ll ans1 = ((q-p+MOD)%MOD*mod_inv<ll>(p-q+r+MOD, MOD))%MOD;
    ll ans2 = ((q-r+MOD)%MOD*mod_inv<ll>(p-q+r+MOD, MOD))%MOD;
    cout << ans2 << " " << ans1 << "\n";
    return 0;
}
