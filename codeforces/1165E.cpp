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

static const int MOD = 998244353;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lli", &x);
        v[i] = x*(n-i)*(i+1);
    }
    vector<ll> u(n);
    for (auto &&i : u) scanf("%lli", &i);
    sort(v.begin(),v.end());
    sort(u.begin(),u.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        (ans += v[i]%MOD*u[i]%MOD) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}