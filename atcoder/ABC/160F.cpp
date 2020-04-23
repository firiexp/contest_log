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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<u32 M = 1000000007>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;

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

Factorial fact(200000);

struct M {
    using T = pair<mint, int>;
    using U = int;
    static T f(T a, T b) { return {a.first*b.first*fact.C(a.second+b.second, a.second), a.second+b.second}; }
    static T g(T a, U b) {
        return {a.first, a.second+b};
    }
    static T e() { return {1, 0}; }
};

int main() {
    int n;
    cin >> n;
    ReRooting<M> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G.add_edge(a, b, 1);
    }
    auto ans = G.solve();
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i].first.val);
    }
    return 0;
}