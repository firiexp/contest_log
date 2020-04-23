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
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        deg[a]++; deg[b]++;
        uf.unite(a, b);
    }
    for (int i = 0; i < k; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        if(uf.same(c, d)){
            deg[c]++; deg[d]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", uf.size(i)-deg[i]-1);
    }
    puts("");
    return 0;
}