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

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

class UnionFind {
    int n;
    vector<int> uni;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

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
        return true;
    }

    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};


int main() {
    int n, m;
    while(cin >> n >> m, n){
        vector<edge<int>> G;
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            a--; b--;
            G.emplace_back(a, b, w);
        }
        sort(G.begin(),G.end(), [](edge<int> e1, edge<int> e2){ return e1.cost > e2.cost; });
        int a = m;
        int ans = INF<int>;
        for (int i = 0; i < m; ++i) {
            UnionFind tree(n);
            int mi = INF<int>, Ma = 0;
            for(int j = (int)G.size()-1; j >= 0; --j) {
                if(tree.unite(G[j].from, G[j].to))  {
                    mi = min(mi, G[j].cost);
                    Ma = max(Ma, G[j].cost);
                }
            }
            if(tree.size(0) == n) ans = min(ans, Ma-mi);
            G.pop_back();
        }
        cout << (ans == INF<int> ? -1 : ans) << "\n";
    }
    return 0;
}