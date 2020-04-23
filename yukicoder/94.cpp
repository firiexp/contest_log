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

class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1), forest_size(n) {};

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
    int n;
    cin >> n;
    if(n == 0){
        puts("1");
        return 0;
    }
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int dx = xs[i]-xs[j], dy = ys[i]-ys[j];
            if(dx*dx+dy*dy <= 100){
                uf.unite(i, j);
            }
        }
    }
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[uf.root(i)].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!v[i].empty()){
            for (int j = 0; j < v[i].size(); ++j) {
                for (int k = j+1; k < v[i].size(); ++k) {
                    int dx = xs[v[i][j]]-xs[v[i][k]], dy = ys[v[i][j]]-ys[v[i][k]];
                    ans = max(ans, dx*dx+dy*dy);
                }
            }
        }
    }
    printf("%.10lf\n", sqrt(ans)+2);
    return 0;
}