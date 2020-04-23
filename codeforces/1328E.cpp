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

class HeavyLightDecomposition {
    void dfs_sz(int v){
        for (auto &&u : G[v]) {
            if(u == par[v]) continue;
            par[u] = v; dep[u] = dep[v] + 1;
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
    G(G), n(G.size()), par(n), dep(n) , sub_size(n, 1), id(n), id_inv(n), tree_id(n), head(n) {}

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
            f(max(id[head[v]], id[u]), id[v]+1);
            if(head[u] == head[v]) {
                if(u == v) break;
                f(id[u], id[v]+1);
            }else {
                v = par[head[v]];
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
    int n, q;
    cin >> n >> q;
    HeavyLightDecomposition G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G.add_edge(a, b);
    }
    G.build();
    for (int i = 0; i < q; ++i) {
        int k;
        scanf("%d", &k);
        vector<int> v(k);
        for (auto &&j : v) scanf("%d", &j), j = G.par[j-1];
        sort(v.begin(),v.end(), [&](int x, int y){
            return G.dep[x] < G.dep[y];
        });
        int ok = 1;
        for (int j = 0; j+1 < k; ++j) {
            int a = v[j], b = v.back(), c = G.lca(a, b);
            if(a != c && b != c){
                puts("NO");
                ok = 0;
                break;
            }
        }
        if(ok){
            puts("YES");
        }
    }
    return 0;
}