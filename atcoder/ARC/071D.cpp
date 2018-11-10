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

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v1(n, 0);
    ll k;
    cin >> k;
    for (int i = 1; i < n; ++i) {
        ll u;
        scanf("%lld", &u);
        v1[i] = (u-k)%MOD;
    }
    vector<ll> t1(n, 0);
    ll s = 0;
    for (int i = 1; i < n; ++i) {
        s = (s + v1[i])%MOD;
        t1[i] = s;
    }
    ll x = 0;
    for (int i = 1; i < n; ++i) {
        x = (x + v1[i]*i+(MOD-t1[i-1]))%MOD;
    }
    vector<ll> v2(m, 0);
    cin >> k;
    for (int i = 1; i < m; ++i) {
        ll u;
        scanf("%lld", &u);
        v2[i] = (u-k)%MOD;
    }
    vector<ll> t2(m, 0);
    s = 0;
    for (int i = 1; i < m; ++i) {
        s = (s + v2[i])%MOD;
        t2[i] = s;
    }
    ll y = 0;
    for (int i = 1; i < m; ++i) {
        y = (y + v2[i]*i+(MOD-t2[i-1]))%MOD;
    }
    cout << (x*y)%MOD << "\n";
    return 0;
}
