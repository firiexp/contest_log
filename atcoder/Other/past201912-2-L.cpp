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

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

class UnionFind {
    vector<int> uni;
    int n;
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
};

template< typename T >
T kruskal(vector<edge<T>> &G, int V)
{
    sort(begin(G), end(G), [](const edge< T > &a, const edge< T > &b) { return (a.cost < b.cost); });
    UnionFind tree(V);
    T ret = 0;
    for(auto &e : G) {
        if(tree.unite(e.from, e.to)) ret += e.cost;
    }
    return (ret);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x1(n), y1(n), c1(n), x2(m), y2(m), c2(m);
    for (int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> c1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x2[i] >> y2[i] >> c2[i];
    }
    double ans = INF<double>;
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                x1.emplace_back(x2[j]);
                y1.emplace_back(y2[j]);
                c1.emplace_back(c2[j]);
            }
        }
        int V = x1.size();
        vector<edge<double>> G;
        for (int j = 0; j < V; ++j) {
            for (int k = j+1; k < V; ++k) {
                G.emplace_back(j, k, hypot(x1[j]-x1[k], y1[j]-y1[k])*(c1[j] == c1[k] ? 1 : 10));
            }
        }
        ans = min(ans, kruskal(G, V));
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                x1.pop_back();
                y1.pop_back();
                c1.pop_back();
            }
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}