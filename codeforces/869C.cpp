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
using u32 = unsigned;
using u64 = unsigned long long;
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


class Factorial {
    using mint = modint<MOD>;
    vector<mint> facts, factinv;

public:
    explicit Factorial(int n) : facts(static_cast<u32>(n+1)), factinv(static_cast<u32>(n+1)) {
        facts[0] = 1;
        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1]*mint(i);
        factinv[n] = facts[n].inv();
        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * mint(i+1);
    }

    mint fact(int k) const {
        if(k >= 0) return facts[k]; else return factinv[-k];
    }

    mint operator[](const int &k) const {
        if(k >= 0) return facts[k]; else return factinv[-k];
    }

    mint C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return facts[p] * factinv[q] * factinv[p-q];
    }

    mint P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return facts[p] * factinv[p-q];
    }

    mint H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return q == 0 ? 1 : C(p+q-1, q);
    }
};


using mint = modint<MOD>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    mint ans = 1;
    Factorial f(a+b+c);
    auto calc = [&](int x, int y){
        mint ret = 0;
        for (int i = 0; i <= min(x, y); ++i) {
            ret += f.C(x, i)*f.P(y, i);
        }
        return ret;
    };
    cout << (calc(a, b)*calc(b, c)*calc(c, a)).val << "\n";
    return 0;
}