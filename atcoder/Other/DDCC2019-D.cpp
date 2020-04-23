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

int ketawa(ll n, int k){
    int ans = 0;
    while(n){
        ans += n % k;
        n /= k;
    }
    return ans;
}


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
    vector<int> v(29);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<ll, ll>> x;

    for (int i = 1; i < 29; ++i) {
        x.emplace_back(v[i]%(i+1), i+1);
    }
    auto w = CRT(x);
    if(w == make_pair((ll)0, (ll)(-1))) {
        cout << "invalid" << "\n";
        return 0;
    }
    ll ans = w.first;
    for (ll j = ans; j <= 1000000000000; j += w.second) {
        int k = 1;
        for (int i = 0; i < 29; ++i) {
            if (ketawa(j, i + 2) != v[i]) k = 0;
        }
        if (k) {
            cout << (long long) j << "\n";
            return 0;
        }
    }
    cout << "invalid" << "\n";
    return 0;
}
