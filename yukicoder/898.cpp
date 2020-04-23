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


template <class F>
struct SparseTable {
    using T = typename F::T;
    vector<vector<T>> table;
    vector<int> u;
    SparseTable() = default;
    explicit SparseTable(const vector<T> &v){ build(v); }

    void build(const vector<T> &v){
        int n = v.size(), m = 1;
        while((1<<m) <= n) m++;
        table.assign(m, vector<T>(n));
        u.assign(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            u[i] = u[i>>1] + 1;
        }
        for (int i = 0; i < n; ++i) {
            table[0][i] = v[i];
        }
        for (int i = 1; i < m; ++i) {
            int x = (1<<(i-1));
            for (int j = 0; j < n; ++j) {
                table[i][j] = F::f(table[i-1][j], table[i-1][min(j+x, n-1)]);
            }
        }
    }

    T query(int a, int b){
        int l = b-a;
        return F::f(table[u[l]][a], table[u[l]][b-(1<<u[l])]);
    }
};


struct F {
    using T = pair<int, int>;
    static T f(T a, T b) { return min(a, b); }
    static T e() { return T{INF<int>, -1}; }
};

class Graph {
    SparseTable<F> table;
    void dfs_euler(int v, int p, int d, int &k){
        id[v] = k;
        vs[k] = v;
        depth[k++] = d;
        for (auto &&u : G[v]) {
            if(u != p){
                dfs_euler(u, v, d+1, k);
                vs[k] = v;
                depth[k++] = d;
            }
        }
    }
public:
    int n;
    vector<vector<int>> G;
    vector<int> vs, depth, id;
    explicit Graph(int n) : n(n), G(n), vs(2*n-1), depth(2*n-1), id(n), table() {};
    void add_edge(int a, int b){
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    void eulertour(int root) {
        int k = 0;
        dfs_euler(root, -1, 0, k);
    }

    void buildLCA(){
        eulertour(0);
        vector<pair<int, int>> v(2*n-1);
        for (int i = 0; i < 2*n-1; ++i) {
            v[i] = make_pair(depth[i], i);
        }
        table.build(v);
    }

    int LCA(int u, int v){
        if(id[u] > id[v]) swap(u, v);
        return table.query(id[u], id[v]+1).second;
    }
};

int main() {
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<vector<P>> G(n);
    Graph LCA(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        LCA.add_edge(u, v);
    }
    vector<ll> dp(n);
    auto dfs = [&](int i, int par, auto &&f) -> void {
        for (auto &&j : G[i]) {
            if(j.first == par) continue;
            dp[j.first] = dp[i] + j.second;
            f(j.first, i, f);
        }
    };
    dfs(0, -1, dfs);
    LCA.buildLCA();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        ll A = dp[x] + dp[y] - dp[LCA.vs[LCA.LCA(x, y)]]*2;
        ll B = dp[y] + dp[z] - dp[LCA.vs[LCA.LCA(y, z)]]*2;
        ll C = dp[z] + dp[x] - dp[LCA.vs[LCA.LCA(z, x)]]*2;
        if(A > B) swap(A, B);
        if(B > C) swap(B, C);
        if(A > B) swap(A, B);
        printf("%lld\n", (A+B+C)/2);
    }
    return 0;
}