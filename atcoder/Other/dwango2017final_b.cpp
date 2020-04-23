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

constexpr int B = 320;

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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    using P = pair<int, int>;
    vector<P> query(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &query[i].first, &query[i].second);
        query[i].first--;
    }
    vector<int> cnt(100011);
    vector<int> mo(q);
    iota(mo.begin(),mo.end(), 0);
    sort(mo.begin(),mo.end(), [&](int a, int b){
        if(query[a].first/B != query[b].first/B) {
            return query[a].first < query[b].first;
        }
        if((query[a].first/B)&1) return query[a].second > query[b].second;
        return query[a].second < query[b].second;
    });
    int M = 100011;
    vector<int> minfactor(M+1, -1);
    for (int i = 2; i <= M; ++i) {
        if(~minfactor[i]) continue;
        for (int j = i; j <= M; j += i) {
            if(!(~minfactor[j])) minfactor[j] = i;
        }
    }
    auto sum = make_v(n+1, B+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= B; ++j) {
            sum[i+1][j] += sum[i][j];
        }
        while(v[i] != 1 && minfactor[v[i]] <= B){
            sum[i+1][minfactor[v[i]]]++;
            v[i] /= minfactor[v[i]];
        }
    }
    vector<mint> rev(M);
    rev[0] = 1;
    for (int i = 1; i < M; ++i) {
        rev[i] = mint(i).inv();
    }
    vector<mint> ret(q);
    mint ans = 1;
    auto multiply = [&](int x){
        ans *= rev[cnt[x]+1];
        cnt[x]++;
        ans *= mint(cnt[x]+1);

    };
    auto divide = [&](int x){
        ans *= rev[cnt[x]+1];
        cnt[x]--;
        ans *= mint(cnt[x]+1);
    };
    int l = 0, r = 0;
    for (int w = 0; w < q; ++w) {
        int left, right; tie(left, right) = query[mo[w]];
        mint ans2 = 1;
        for (int i = 2; i <= B; ++i) {
            ans2 *= mint(sum[right][i]-sum[left][i]+1);
        }
        while(left < l){
            l--;
            if(v[l] != 1) multiply(v[l]);
        }
        while(r < right){
            if(v[r] != 1) multiply(v[r]);
            r++;
        }
        while(l < left){
            if(v[l] != 1) divide(v[l]);
            l++;
        }
        while(right < r){
            r--;
            if(v[r] != 1) divide(v[r]);
        }
        ret[mo[w]] = ans*ans2;
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ret[i].val);
    }
    return 0;
}