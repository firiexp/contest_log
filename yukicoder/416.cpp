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

struct QuickFind {
    int n;
    vector<int> roots;
    vector<vector<int>> v;
    explicit QuickFind(int n) : n(n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) v[i].emplace_back(i);
        roots.resize(n);
        iota(roots.begin(),roots.end(), 0);
    }

    int root(int a){ return roots[a]; }
    size_t size(int a){ return v[a].size(); }
    bool unite(int a, int b){
        if(same(a, b)) return false;
        a = roots[a], b = roots[b];
        if(size(a) < size(b)) swap(a, b);
        for (auto &&i : v[b]) {
            v[a].emplace_back(i);
            roots[i] = a;
        }
        v[b].clear();
        v[b].shrink_to_fit();
        return true;
    }
    bool same(int a, int b){ return roots[a] == roots[b]; }
    const vector<int>& components(int x){ return v[roots[x]];}
};


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> A(m), B(q);
    for (int i = 0; i < m; ++i) scanf("%d %d", &A[i].first, &A[i].second);
    for (int i = 0; i < q; ++i) scanf("%d %d", &B[i].first, &B[i].second);
    set<pair<int, int>> S(B.begin(),B.end());
    vector<int> ans(n);
    QuickFind G(n);
    for (int i = 0; i < m; ++i) {
        if(S.count(A[i])) continue;
        int a, b; tie(a, b) = A[i];
        a--; b--;
        if(G.roots[a] == G.roots[b]) continue;
        if(G.roots[a] == G.roots[0]){
            for (auto &&j : G.components(b)) ans[j] = -1;
        }else if(G.roots[b] == G.roots[0]){
            for (auto &&j : G.components(a)) ans[j] = -1;
        }
        G.unite(a, b);
    }
    for (int i = q-1; i >= 0; --i) {
        int a, b; tie(a, b) = B[i];
        a--; b--;
        if(G.roots[a] == G.roots[b]) continue;
        if(G.roots[a] == G.roots[0]){
            for (auto &&j : G.components(b)) ans[j] = i+1;
        } else if(G.roots[b] == G.roots[0]){
            for (auto &&j : G.components(a)) ans[j] = i+1;
        }
        G.unite(a, b);
    }
    for (int i = 1; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}