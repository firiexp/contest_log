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
vector<ll> v(51), u(51);

ll solve(ll n, ll x){
    if(x <= n) return 0;
    if(n == 0 && x == 1) return 1;
    if(n == 0) return 0;
    ll ans = 0;
    if(v[n-1]+1 <= x) {
        ans += u[n-1];
        if(v[n-1]+2 <= x) ans++;
        if(2*v[n-1]+2 <= x) ans += u[n-1];
        else ans += solve(n-1, x-v[n-1]-2);
    }
    else ans += solve(n-1, x-1);

    return ans;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    u[0] = 1;
    v[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        v[i] = v[i-1]*2+3;
        u[i] = u[i-1]*2+1;
    }
    ll n, x;
    cin >> n >> x;
    cout << solve(n, x) << "\n";
    return 0;
}
