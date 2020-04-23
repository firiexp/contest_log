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
    for (int i = 0; i < a.size(); ++i) {
        ll p, q;
        ll d = extgcd(M, a[i].second, p, q);
        if((a[i].first - r )%d != 0) return make_pair(0, -1);
        ll tmp = (a[i].first - r) / d * p % (a[i].second / d);
        r += M * tmp;
        M *= a[i].second/d;
    }
    return make_pair((r+M) % M, M);
}

int main() {
    vector<pair<ll, ll>> v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    auto ret = CRT(v);
    cout << (ret.second == -1 ? -1 : (ret.first == 0 ? ret.first+ret.second : ret.first)) << "\n";
    return 0;
}