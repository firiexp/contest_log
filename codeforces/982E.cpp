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

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};


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

pair<ll, ll> CRT(const vector<pair<ll, ll>> &a){
    ll r = 0, M = 1;
    for (const auto & i : a) {
        ll p, q;
        ll d = extgcd(M, i.second, p, q);
        if((i.first - r )%d != 0) return make_pair(0, -1);
        ll tmp = (i.first - r) / d * p % (i.second / d);
        r += M * tmp;
        M *= i.second/d;
    }
    return make_pair((r+M) % M, M);
}
int main() {
    int n, m, sx, sy, vx, vy;
    cin >> n >> m >> sx >> sy >> vx >> vy;
    if(vx == 0){
        if(sx == 0 || sx == m){
            if(vy < 0) printf("%d %d\n", sx, 0);
            else printf("%d %d\n", sx, m);
        }else puts("-1");
        return 0;
    }else if(vy == 0){
        if(sy == 0 || sy == m){
            if(vx < 0) printf("%d %d\n", 0, sy);
            else printf("%d %d\n", m, sy);
        }else puts("-1");
        return 0;
    }
    int xs[] = {0, 0, n, n},
        ys[] = {0, m, 0, m};
    auto check = [=](int gx, int gy) -> ll {
        ll dx = (gx-sx), dy = gy-sy;
        if(vx < 0) dx = -dx;
        if(vy < 0) dy = -dy;
        vector<pair<ll, ll>> v{{dx, 2*n}, {dy, 2*m}};
        auto vv = CRT(v);
        return (vv.second < 0 ? -1 : vv.first);
    };
    ll ans = -1, ret = -1;
    for (int i = 0; i < 4; ++i) {
        ll x = check(xs[i], ys[i]);
        if(x >= 0 && (ans < 0 || x < ans)){
            ans = x;
            ret = i;
        }
    }
    if(ret != -1){
        printf("%d %d\n", xs[ret], ys[ret]);
    }else {
        puts("-1");
    }
    return 0;
}