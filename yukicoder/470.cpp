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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

struct SCC {
    vector<vector<int>> G, G_r, G_out;
    vector<int> vs, used, cmp;
    SCC() = default;
    explicit SCC(int n) : G(n), G_r(n), G_out(n), used(n), cmp(n) {}

    void add_edge(int a, int b){
        G[a].emplace_back(b);
        G_r[b].emplace_back(a);
    }

    void dfs(int v){
        used[v] = 1;
        for (auto &&u : G[v]) if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }

    void dfs_r(int v, int k){
        used[v] = 1;
        cmp[v] = k;
        for (auto &&u : G_r[v]) if(!used[u]) dfs_r(u, k);
    }

    int build() {
        int n = G.size();
        for (int i = 0; i < n; ++i) if(!used[i]) dfs(i);
        fill(used.begin(),used.end(), 0);
        int k = 0;
        for (int i = n - 1; i >= 0; --i) {
            if(!used[vs[i]]){
                dfs_r(vs[i], k++);
            }
        }
        G_out.resize(k);
        for (int i = 0; i < n; ++i) {
            for (auto &&j : G[i]) {
                if(cmp[i] != cmp[j]){
                    G_out[cmp[i]].emplace_back(cmp[j]);
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            sort(G_out.begin(), G_out.end());
            G_out.erase(unique(G_out.begin(), G_out.end()), G_out.end());
        }
        return k;
    }

    int operator[](int k) const { return cmp[k]; }
};

struct TwoSAT {
    int n;
    SCC scc;
    explicit TwoSAT(int n) : n(n), scc(n*2) {};
    int negate(int v){
        int ret = n+v;
        if(ret >= n*2) ret -= n*2;
        return ret;
    }

    vector<int> build() {
        scc.build();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if(scc[i] == scc[n+i]) return {};
            res[i] = scc[i] > scc[n+i];
        }
        return res;
    }

    void add_if(int u, int v){ // u -> v
        scc.add_edge(u, v);
        scc.add_edge(negate(v), negate(u));
    }

    void add_or(int u, int v){ // u || v
        add_if(negate(u), v);
    }
};

int main() {
    int n;
    cin >> n;
    if(n > 52){
        puts("Impossible");
        return 0;
    }
    vector<string> v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    TwoSAT G(n);
    vector<string> a(2*n), b(2*n);
    for (int i = 0; i < n; ++i) {
        a[i] = v[i].substr(0, 1);
        a[i+n] = v[i].substr(2, 1);
        b[i] = v[i].substr(1, 2);
        b[i+n] = v[i].substr(0, 2);
    }
    for (int i = 0; i < 2*n; ++i) {
        for (int j = i+1; j < 2*n; ++j) {
            if(a[i] == a[j] || b[i] == b[j]){
                G.add_if(i, G.negate(j));
            }
        }
    }

    auto ret = G.build();
    if(ret.empty()){
        puts("Impossible");
    }else {
        for (int i = 0; i < n; ++i) {
            if(ret[i]){
                cout << a[i] << " " << b[i] << "\n";
            }else {
                cout << b[i+n] << " " << a[i+n] << "\n";
            }
        }
    }
    return 0;
}