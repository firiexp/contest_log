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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, l, t;
    cin >> n >> l >> t;
    vector<pair<ll, ll>> v(n);
    vector<ll> u(n);
    ll k = 0;
    ll cnt = n*MOD;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        scanf("%li %li", &a, &b);
        v[i] = make_pair(a, b);
        u[i] = ((a+(b == 1 ? t : -t) + l*MOD)%l);
        if(i == 0) k = u[i];
        if(b == 1) cnt -= (t-l+a+l)/l;
        else cnt += (t-a-1+l)/l;
    }
    cnt %= n;
    sort(u.begin(), u.end());
    for (int i = 0; i < n; ++i) {
        printf("%li\n", u[(-cnt+n+i)%n]);
    }
    return 0;
}
