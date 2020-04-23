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
    int n;
    cin >> n;
    ll k = 1;
    vector<vector<ll>> v(n);
    vector<ll> seki(n+1, 1);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        v[i].resize(m);
        seki[i+1] = m;
        for (auto &&j : v[i]) scanf("%lli", &j);
    }
    for (int i = 1; i <= n; ++i) {
        (seki[i] *= seki[i-1]) %= MOD;
    }
    reverse(seki.begin(),seki.end());
    reverse(v.begin(),v.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll k2 = 0;
        for (ll j : v[i]) {
            (ans += k*j%MOD*seki[i+1]) %= MOD;
            ll a = 1;
            while(a <= j) a *= 10;
            (k2 += a) %= MOD;
        }
        (k *= k2) %= MOD;

    }
    cout << ans << "\n";
    return 0;
}