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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

ll get_interval(vector<pair<ll, ll>> &v){
    int n = v.size();
    vector<ll> z(2*n);
    for (int i = 0; i < n; ++i) {
        z[2*i] = v[i].first; z[2*i+1] = v[i].second;
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    vector<ll> s(z.size()+1);
    auto f = [&](ll x){ return lower_bound(z.begin(),z.end(), x) - z.begin(); };
    for (int i = 0; i < n; ++i) {
        s[f(v[i].first)]++; s[f(v[i].second)]--;
    }
    ll ret = 0;
    for (int i = 0; i+1 < z.size(); ++i) {
        s[i+1] += s[i];
        if(s[i] > 0){
            ret += z[i+1]-z[i];
        }
    }
    return ret;
}

ll s(ll l, ll r){ // lからrまでの和
    if(l > r) return 0;
    return (r-l+1)*(2*l+(r-l))/2;
}

int main() {
    ll n, x, d;
    cin >> n >> x >> d;
    if(d == 0){
        if(x == 0) puts("1");
        else cout << n+1 << "\n";
        return 0;
    }
    if(d < 0) d *= -1, x *= -1;
    vector<tuple<int, ll, ll>> u;
    for (int i = 0; i <= n; ++i) {
        ll X = (n-2*(n-i))*x+s(1, n-1)*d;
        ll l = 0, r = 0;
        l = s(0, i-1), r = s(n-i, n-1);
        l += X/(2*d), r += X/(2*d); X %= (2*d);
        if(X < 0){
            X += 2*d; l--; r--;
        }
        u.emplace_back(X, l, r+1);
    }
    sort(u.begin(),u.end());
    ll ans = 0, cur = 0;
    int m = u.size();
    vector<pair<ll, ll>> p;
    while(cur < m){
        ll curr = cur;
        while(curr < m && get<0>(u[cur]) == get<0>(u[curr])) {
            int a; ll b, c;
            tie(a, b, c) = u[curr];
            curr++;
            p.emplace_back(b, c);
        }
        ans += get_interval(p);
        p.clear();
        cur = curr;
    }
    cout << ans << "\n";
    return 0;
}