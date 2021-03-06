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

class Factorial {
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
};

using mint = modint<MOD>;
constexpr int M = 1000000;
int main() {
    int n;
    cin >> n;
    mint ans = 0;
    vector<mint> v(M+1);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x] += mint(1);
        ans -= mint(x);
    }
    for (int i = 1; i <= M; ++i) {
        v[i] *= mint(i);
    }
    vector<int> sieve(M+1);
    for (int i = 2; i <= M; ++i) {
        if(!sieve[i]){
            for (int j = M/i; j != 0; --j) {
                if(j != 1) sieve[j*i] = true;
                v[j] += v[j*i];
            }
        }
    }
    for (int i = 1; i <= M; ++i) {
        v[i] *= v[i];
    }
    for (int i = 2; i <= M; ++i) {
        if(!sieve[i]){
            for (int j = 1; j*i <= M; ++j) {
                if(j != 1) sieve[j*i] = true;
                v[j] -= v[j*i];
            }
        }
    }
    Factorial f(M);
    for (int i = 1; i <= M; ++i) {
        ans += v[i]*f[i-1]*f[-i];
    }
    cout << (ans*mint(499122177)).val << "\n";
    return 0;
}