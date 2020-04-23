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
    ll p, q, l, r;
    cin >> p >> q >> l >> r;
    auto f = [](ll p, ll q, ll x){
        vector<ll> v(100), u(100);
        v[0] = x;
        for (int i = 1; i < 100; ++i) {
            v[i] = v[i-1]/p;
        }
        for (int i = 0; i < 100; ++i) {
            u[i] = (1+v[i]);
            if(v[i]%2 == 0) {
                u[i] /= 2;
                u[i] = u[i]/2%q*(1+v[i])%q;
            }
            else {
                u[i] = u[i]%q*((1+v[i])/2)%q;
            }
        }
        ll pp = 1, ans = 0;
        for (int i = 0; i < 101; ++i) {
            ans += u[i]+(q-pp)*u[i+11];
            pp = pp*p%q;
        }
        return ans;
    };
    cout << f(p, q, r)-f(p, q, l-1);
    return 0;
}