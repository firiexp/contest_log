#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

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
void solve(){
    vector<int> v{7, 11, 12, 13, 15, 16, 17};
    vector<pair<ll, ll>> a;
    for (int i : v) {
        for (int j = 0; j < 18; ++j) {
            if(j) cout << " ";
            cout << i;
        }
        cout << endl;
        int p = 0;
        for (int j = 0; j < 18; ++j) {
            int q;
            cin >> q;
            if(q == -1){
                exit(0);
            }
            (p += q) %= i;
        }
        a.emplace_back(p, i);
    }
    cout << CRT(a).first << endl;
    int verdict;
    cin >> verdict;
    if(verdict == -1) exit(0);
}

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}
