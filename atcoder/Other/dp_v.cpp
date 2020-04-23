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

struct modint {
    ll val;
    static ll &mod(){
        static ll mod_ = 1;
        return mod_;
    }

    static void set_mod(const ll x) { mod() = x; }
    static ll M() {return mod(); }

    modint(const ll x = 0) : val(x) {
        val = x%M();
        while(val < 0) val += M();
    }
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return {M()-val}; }
    modint inv() const {
        ll u = 1, v = 0, s = 0, t = 1, m = M(), x = val;
        while (x) {ll q = M()/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M();
        return modint(s);
    }
    modint pow(ll n){
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M(); xx = xx * xx % M(); n >>= 1; }
        return modint(u);
    }
    modint& operator+=(const modint a){ val += a.val; if(val >= M()) val -= M(); return *this; }
    modint& operator-=(const modint a){ val += a.val; if(val < 0) val += M(); return *this; }
    modint& operator*=(const modint a){ val = val * a.val % M(); return *this; }
    modint& operator/=(const modint a){ val = val * a.inv().val % M(); return *this;}

    modint& operator=(const int& x){
        val = x%M();
        while(val < 0) val += M();
        return *this;
    }
};
using mint = modint;

template<typename M>
class ReRooting {
public:
    using T = typename M::T;
    using U = typename M::U;
    struct Node {
        int to, rev;
        U val;
        Node(int u, int v, U val) : to(u), rev(v), val(val) {};
    };
    int n;
    vector<vector<Node>> G;
    vector<vector<T>> dpl, dpr;
    vector<int> l, r;

    explicit ReRooting(int n) : n(n), G(n), dpl(n), dpr(n), l(n), r(n) {};

    void add_edge(int u, int v, const U &x) {
        G[u].emplace_back(v, G[v].size(), x);
        G[v].emplace_back(u, G[u].size()-1, x);
    }
    void add_edge(int u, int v, const U &x, const U &y) {
        G[u].emplace_back(v, G[v].size(), x);
        G[v].emplace_back(u, G[u].size()-1, y);
    }

    T dfs(int i, int par){
        while(l[i] != par && l[i] < G[i].size()){
            auto &e = G[i][l[i]];
            dpl[i][l[i] + 1] = M::f(dpl[i][l[i]], M::g(dfs(e.to, e.rev), e.val));
            ++l[i];
        }
        while(r[i] != par && r[i] >= 0){
            auto &e = G[i][r[i]];
            dpr[i][r[i]] = M::f(dpr[i][r[i] + 1], M::g(dfs(e.to, e.rev), e.val));
            --r[i];
        }
        if(par < 0) return dpr[i].front();
        return M::f(dpl[i][par], dpr[i][par+1]);
    }

    vector<T> solve(){
        for (int i = 0; i < n; ++i) {
            dpl[i].assign(G[i].size()+1, M::e());
            dpr[i].assign(G[i].size()+1, M::e());
            l[i] = 0;
            r[i] = (int)G[i].size() - 1;
        }
        vector<T> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dfs(i, -1);
        }
        return ans;
    }
};

struct M {
    using T = mint;
    using U = mint;
    static T f(T a, T b) { return a*b; }
    static T g(T a, U b) {
        return a+b;
    }
    static T e() { return {1}; }
};

int main() {
    int n, m;
    cin >> n >> m;
    mint x(0);
    x.set_mod(m);
    ReRooting<M> G(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G.add_edge(u, v, 1);

    }
    auto ans = G.solve();
    for (auto &&i : ans) {
        printf("%lld\n", i.val);
    }
    return 0;
}