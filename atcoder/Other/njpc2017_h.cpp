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

template <class M>
struct LazySegmentTree{
    using T = typename M::T;
    using L = typename M::L;
    int sz, height{};
    vector<T> seg; vector<L> lazy;
    explicit LazySegmentTree(int n) {
        sz = 1; while(sz < n) sz <<= 1, height++;
        seg.assign(2*sz, M::e());
        lazy.assign(2*sz, M::l());
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = M::f(seg[i<<1], seg[(i<<1)|1]);
    }

    T reflect(int k){ return lazy[k] == M::l() ? seg[k] : M::g(seg[k], lazy[k]); }

    void eval(int k){
        if(lazy[k] == M::l()) return;
        lazy[(k<<1)|0] = M::h(lazy[(k<<1)|0], lazy[k]);
        lazy[(k<<1)|1] = M::h(lazy[(k<<1)|1], lazy[k]);
        seg[k] = reflect(k);
        lazy[k] = M::l();
    }
    void thrust(int k){ for (int i = height; i; --i) eval(k>>i); }
    void recalc(int k) { while(k >>= 1) seg[k] = M::f(reflect((k<<1)|0), reflect((k<<1)|1));}
    void update(int a, int b, const L &x){
        thrust(a += sz); thrust(b += sz-1);
        for (int l = a, r = b+1;l < r; l >>=1, r >>= 1) {
            if(l&1) lazy[l] = M::h(lazy[l], x), l++;
            if(r&1) --r, lazy[r] = M::h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    T query(int a, int b){ // [l, r)
        thrust(a += sz);
        thrust(b += sz-1);
        T ll = M::e(), rr = M::e();
        for(int l = a, r = b+1; l < r; l >>=1, r>>=1) {
            if (l & 1) ll = M::f(ll, reflect(l++));
            if (r & 1) rr = M::f(reflect(--r), rr);
        }
        return M::f(ll, rr);
    }
};

struct Monoid{
    using T = int;
    using L = int;
    static T f(T a, T b) {
        return a|b;
    }
    static T g(T a, L b) {
        if(b) return ((a&1) << 1)|((a&2) >> 1);
        else return a;
    }
    static L h(L a, L b) {
        return a^b;
    }
    static T e() { return 0; }
    static L l() { return 0; }
};

class HeavyLightDecomposition {
    void dfs_sz(int v){
        for (auto &&u : G[v]) {
            if(u == par[v]) continue;
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub_size[v] += sub_size[u];
            if(sub_size[u] > sub_size[G[v][0]]) swap(u, G[v][0]);
        }
    }

    void dfs_hld(int v, int c, int &pos){
        id[v] = pos++;
        id_inv[id[v]]= v;
        tree_id[v] = c;
        for (auto &&u : G[v]) {
            if(u == par[v]) continue;
            head[u] = (u == G[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
    }

public:
    int n;
    vector<vector<int>> G;
    vector<int> par, dep, sub_size, id, id_inv, tree_id, head;
    explicit HeavyLightDecomposition(int n) : n(n), G(n), par(n), dep(n), sub_size(n, 1),
                                              id(n), id_inv(n), tree_id(n), head(n){}
    explicit HeavyLightDecomposition(vector<vector<int>> &G) :
            G(G), n(n), par(n), dep(n) , sub_size(n, 1), id(n), id_inv(n), tree_id(n), head(n) {}

    void add_edge(int u, int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(vector<int> roots = {0}){
        int c = 0, pos = 0;
        for (auto &&i : roots) {
            dfs_sz(i);
            head[i] = i;
            dfs_hld(i, c++, pos);
        }
    }

    int lca(int u, int v){
        while(true){
            if(id[u] > id[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v){
        return dep[u] + dep[v] - 2*dep[lca(u, v)];
    }


    template<typename F>
    void query(int u, int v, const F &f){
        while(true){
            if(id[u] > id[v]) swap(u, v);
            f(max(id[head[v]], id[u]), id[v]+1);
            if(head[u] == head[v]) break;
            v = par[head[v]];
        }
    }

    template<typename F>
    void query_edge(int u, int v, const F &f){
        while(true){
            if(id[u] > id[v]) swap(u, v);
            if(head[u] != head[v]) {
                f(id[head[v]], id[v]+1);
                v = par[head[v]];
            }else {
                if(u != v) f(id[u]+1, id[v]+1);
                break;
            }
        }
    }

    template<typename T, typename Q, typename F>
    T query(int u, int v, const T &e, const Q &q, const F &f){
        T l = e, r = e;
        while(true){
            if(id[u] > id[v]) swap(u, v), swap(l, r);
            l = f(l, q(max(id[head[v]], id[u]), id[v]+1));
            if(head[u] != head[v]) v = par[head[v]];
            else break;
        }
        return f(l, r);
    }
};

int main() {
    int n;
    cin >> n;
    HeavyLightDecomposition G(n);
    LazySegmentTree<Monoid> seg(n);
    vector<int> dep(n);
    for (int i = 1; i < n; ++i) {
        int x; scanf("%d", &x);
        G.add_edge(x-1, i);
    }
    G.build();
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);
        seg.set(G.id[i], 1 << (c^(G.dep[i]&1)));
    }
    seg.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if(t == 1){
            int a; scanf("%d", &a); a--;
            seg.update(G.id[a], G.id[a]+G.sub_size[a], 1);
        }else {
            int a, b; scanf("%d %d", &a, &b); a--; b--;
            int ret = 0;
            auto f = [&](int x, int y){ ret |= seg.query(x, y); };
            G.query(a, b, f);
            if(ret <= 2) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}