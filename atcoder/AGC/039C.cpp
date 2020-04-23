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
#include <cassert>

static const int MOD = 998244353;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <ll M = MOD> struct modint {
    ll val;
    modint(const ll x = 0) : val(x) {
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
    }

    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv() const {
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n) const {
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return modint(u);
    }
    modint& operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint& operator-=(const modint a){ val -= a.val; if(val < 0) val += M; return *this; }
    modint& operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint& operator/=(const modint a){ val = val * a.inv().val % M; return *this;}

    modint& operator=(const int& x){
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
        return *this;
    }
};

using mint = modint<MOD>;

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    ll n; string s;
    cin >> n >> s;
    mint ans = 0, k = 1;
    auto d = divisor(n);
    map<int, mint> m;
    reverse(d.begin(),d.end());
    for (auto &&x : d) {
        if(!(x & 1)) continue;
        int y = n/x;
        string A = s.substr(0, y);
        string B = A;
        for (auto &&j : B) {
            j = (j == '1' ? '0' : '1');
        }
        mint p = 1; k = 1;
        for (ll i = y-1; i >= 0; --i) {
            if(s[i] == '1') p += k;
            k *= mint(2);
        }
        int ok = 1;
        for (ll i = 1; i < x; ++i) {
            auto X = s.substr(i*y, y);
            if(i & 1) {
                if(B > X) ok = 0;
                if(B < X) break;
            }else {
                if(A > X) ok = 0;
                if(A < X) break;
            }
        }
        if(!ok) p -= 1;
        for (auto &&l : m) {
            if((l.first) % x == 0) p -= l.second;
        }
        m[x] = p;
    }
    for (auto &&l : m) {
        ans += l.second*mint(2*(n/l.first));
    }
    cout << ans.val << "\n";
    return 0;
}