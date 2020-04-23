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

constexpr int B = 45;

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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}



int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    using P = pair<int, int>;
    vector<P> query(q);
    for (int i = 0; i < q; ++i) {
        cin >> query[i].first >> query[i].second;
    }
    vector<int> mo(q);
    iota(mo.begin(),mo.end(), 0);
    sort(mo.begin(),mo.end(), [&](int a, int b){
        if(query[a].first/B != query[b].first/B) {
            return query[a].first < query[b].first;
        }
        return query[a].second < query[b].second;
    });
    vector<mint> ans(n+1);
    ans[0] = 1;
    vector<int> cnt(n);
    int l = 0, r = 0;
    auto multiply = [&](int p){
        mint x = p;
        for (int i = n-1; i >= 0; --i) {
            ans[i+1] -= ans[i]*x;
        }
    };
    auto divide = [&](int p){
        mint x = p;
        for (int i = 0; i < n; ++i) {
            ans[i+1] += ans[i]*x;
        }
    };
    vector<mint> ret(q);
    Factorial f(n);
    for (int w = 0; w < q; ++w) {
        int left, right; tie(left, right) = query[mo[w]];
        while(l < left){
            divide(cnt[v[l]]);
            multiply(cnt[v[l]]-1);
            cnt[v[l]]--;
            l++;
        }
        while(left < l){
            l--;
            divide(cnt[v[l]]);
            multiply(cnt[v[l]]+1);
            cnt[v[l]]++;

        }
        while(r < right){
            divide(cnt[v[r]]);
            multiply(cnt[v[r]]+1);
            cnt[v[r]]++;
            r++;
        }
        while(right < r){
            r--;
            divide(cnt[v[r]]);
            multiply(cnt[v[r]]-1);
            cnt[v[r]]--;
        }
        for (int i = 0; i <= n; ++i) {
            ret[mo[w]] += f[n-i]*ans[i];
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ret[i].val << "\n";
    }
    return 0;
}