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

template <class M>
struct SegmentTree{
    using T = typename M::T;
    int sz;
    vector<T> seg;
    explicit SegmentTree(int n) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2*sz, M::e());
    }

    void set(int k, const T &x){ seg[k + sz] = x; }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = M::f(seg[2*i], seg[2*i+1]);
    }

    void update(int k, const T &x){
        k += sz;
        seg[k] = x;
        while (k >>= 1) seg[k] = M::f(seg[2*k], seg[2*k+1]);
    }

    T query(int a, int b){
        T l = M::e(), r = M::e();
        for(a += sz, b += sz; a < b; a >>=1, b>>=1){
            if(a & 1) l = M::f(l, seg[a++]);
            if(b & 1) r = M::f(seg[--b], r);
        }
        return M::f(l, r);
    }

    template<typename C>
    int find(int t, C &c, T &val, int k, int l, int r){
        if(r-l == 1){
            val = f(val, seg[k]);
            return c(val) ? k-sz : -1;
        }
        int m = (l+r) >> 1;
        if(m <= t) return find(t, c, val, (k << 1) | 1, m, r);
        if(t <= l && !c(val = f(val, seg[k]))) return -1;
        int lv = find(t, c, val, (k << 1) | 0 , l, m);
        if(~lv) return lv;
        return find(t, c, val, (k << 1) | 1, m, r);
    }

    template<typename C>
    int find(int t, C &c){
        T val = M::e();
        return find(t, c, val, 1, 0, sz);
    }
    T operator[](const int &k) const { return seg[k + sz]; }
};


struct Monoid{
    using T = pair<int, int>;
    static T f(T a, T b) { return {a.first+b.first, a.second+b.second}; }
    static T e() { return {0, 0}; }
};



int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<tuple<int, int, int, int>>> query(n);
    vector<vector<int>> colors(n);
    vector<array<int, 4>> edges(n-1);
    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c, d;
        scanf("%d %d %d %d", &u, &v, &c, &d);
        u--; v--;
        hld.add_edge(u, v);
        edges[i] = {u, v, c, d};
        colors[c-1].emplace_back(i);
    }
    for (int i = 0; i < q; ++i) {
        int x, y, u, v;
        scanf("%d %d %d %d", &x, &y, &u, &v);
        u--; v--;
        query[x-1].emplace_back(y, u, v, i);
    }
    hld.build();
    vector<int> ans(q);
    SegmentTree<Monoid> seg(n);
    for (auto &&e : edges) {
        if(hld.dep[e[0]] > hld.dep[e[1]]) swap(e[0], e[1]);
        seg.set(hld.id[e[1]], {e[3], 0});
    }

    seg.build();
    for (int i = 0; i < n; ++i) {
        if(!query[i].empty()){
            for (auto &&j : colors[i]) {
                auto &e = edges[j];
                if(hld.dep[e[0]] > hld.dep[e[1]]) swap(e[0], e[1]);
                seg.update(hld.id[e[1]], {0, 1});
            }
            for (auto &&k : query[i]) {
                pair<int, int> res{0, 0};
                auto f = [&](int l, int r){ res = Monoid::f(res, seg.query(l, r)); };
                int y, u, v, j; tie(y, u, v, j) = k;
                hld.query_edge(u, v, f);
                ans[j] = res.first+res.second*y;
            }
            for (auto &&j : colors[i]) {
                auto &e = edges[j];
                if(hld.dep[e[0]] > hld.dep[e[1]]) swap(e[0], e[1]);
                seg.update(hld.id[e[1]], {e[3], 0});
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}