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

template<class T>
class BIT {
    vector<T> bit;
public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};

template <ll M = MOD> struct modint {
public:
    ll val;
    explicit modint(const ll x = 0) : val(x) {}
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv(){
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n){
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return u;
    }
    modint &operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint &operator-=(const modint a){ val -= a.val; if(val < 0) val += M; return *this; }
    modint &operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint &operator/=(const modint a){ val = (val*a.inv()) %M; return *this;}
};

using mint = modint<MOD>;

int main() {
    int n;
    cin >> n;
    vector<mint> pow2(n+1, mint(1));
    for (int i = 0; i < n; ++i) {
        pow2[i+1] = pow2[i]*mint(2);
    }
    vector<pair<int, int>> v(n);
    for (auto &&i : v) scanf("%d %d", &i.first, &i.second);
    vector<int> z(n);
    for (int i = 0; i < n; ++i) {
        z[i] = v[i].second;
    }
    sort(z.begin(),z.end());
    for (int i = 0; i < n; ++i) {
        v[i].second = lower_bound(z.begin(),z.end(), v[i].second) - z.begin();
    }
    sort(v.begin(),v.end());
    vector<ll> A(n), B(n), C(n), D(n);
    BIT<ll> b(n);
    for (int i = 0; i < n; ++i) {
        A[i] = b.sum(v[i].second);
        B[i] = i - A[i];
        b.add(v[i].second+1, 1);
    }
    b = BIT<ll>(n);
    for (int i = n - 1; i >= 0; --i) {
        C[i] = b.sum(v[i].second);
        D[i] = n-i-1- C[i];
        b.add(v[i].second+1, 1);
    }
    mint ans = pow2[n]*mint(n)-mint(n), ans2(0);
    for (int i = 0; i < n; ++i) {
        ans2 += pow2[A[i]]+pow2[B[i]]+pow2[C[i]]+pow2[D[i]]+mint(-4)+(pow2[A[i]]+pow2[D[i]]+mint(-2))*(pow2[B[i]]+pow2[C[i]]+mint(-2));
    }
    cout << (ans-ans2).val << "\n";
    return 0;
}