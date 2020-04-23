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

class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    explicit UnionFind(int n) : n(n), uni(static_cast<size_t>(n), -1), forest_size(n) {};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        forest_size--;
        return true;
    }
    int size(){ return forest_size; }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int>(w+2, -1));
    vector<int> val(h*w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i+1][j+1];
            val[i*w+j] = v[i+1][j+1];
        }
    }
    UnionFind uf(h*w);
    vector<vector<int>> G(h*w);
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    auto f = [&](int i, int j){ return i*w+j; };
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i+1+dy[k]][j+1+dx[k]] < 0) continue;
                if(v[i+1+dy[k]][j+1+dx[k]] == v[i+1][j+1]) {
                    uf.unite(f(i, j), f(i+dy[k], j+dx[k]));
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i+1+dy[k]][j+1+dx[k]] < 0) continue;
                if(v[i+1+dy[k]][j+1+dx[k]] != v[i+1][j+1]) {
                    G[uf.root(f(i, j))].emplace_back(uf.root(f(i+dy[k], j+dx[k])));
                    G[uf.root(f(i, j))].emplace_back(uf.root(f(i+dy[k], j+dx[k])));
                }
            }
        }
    }
    for (int i = 0; i < h*w; ++i) {
        sort(G[i].begin(), G[i].end());
        G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        int x = uf.root(f(a, b));
        if(val[x] == c) continue;
        vector<int> p;
        for (auto &&j : G[x]) {
            for (auto &&k : G[uf.root(j)]) {
                if(uf.root(k) != x) p.emplace_back(uf.root(k));
            }
            G[uf.root(j)].clear();
        }
        for (auto &&j : G[x]) {
            uf.unite(j, x);
        }
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        val[uf.root(x)] = c;
        G[uf.root(x)] = p;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) printf(" ");
            printf("%d", val[uf.root(f(i, j))]);
        }
        puts("");
    }
    return 0;
}