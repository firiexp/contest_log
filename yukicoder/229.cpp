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

pair<ll, ll> f(ll p, ll q, ll r, ll s){
    r *= q; p *= s;
    r /= __gcd(r, p);
    ll g = __gcd(r, q);
    r /= g, q /= g;
    g = __gcd(r, s);
    r /= g, s /= g;
    g = __gcd(p, q);
    p /= g, q /= g;
    g = __gcd(p, s);
    p /= g, s /= g;
    ll ans1 = r*p, ans2 = q*s;
    return {ans1, ans2};
}



template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << p.first << "/" << p.second;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto g = [&](pair<ll, ll> x, pair<ll, ll> y){
        ll g = __gcd(x.first, y.second);
        ll h = __gcd(x.second, y.first);
        return x.first/g*y.second < x.second/h*y.first;
    };
    vector<pair<ll, ll>> ans;

    ans.emplace_back(f(a*b, b-a, a*c, c-a));
    ans.emplace_back(f(a*b, b+a, a*c, c-a));
    ans.emplace_back(f(a*b, b-a, a*c, c+a));
    ans.emplace_back(f(a*b, b+a, a*c, c+a));
    cout << *min_element(ans.begin(),ans.end(), g) << "\n";
    return 0;
}