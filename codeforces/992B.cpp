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

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return(ret);
}

int main() {
    ll l, r ,x, y, ans = 0;
    cin >> l >> r >> x >> y;
    auto v = divisor(y);
    vector<ll> v2;
    for (auto &&i : v) {
        if(l <= i && i <= r) v2.emplace_back(i);
    }
    for (auto &&i : v2) {
        for (auto &&j : v2) {
            if(__gcd(i, j) == x && i*j/__gcd(i, j) == y) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
