#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> va(m), vb(m), vc(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &va[i], &vb[i], &vc[i]);
    }
    for (int i = 0; i < k; ++i) {
        int e;
        scanf("%d", &e);
        vc[e-1] = 0;
    }
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += vc[i];
    }
    vector<edge<ll>> v;
    v.reserve(m);
    for (int i = 0; i < m; ++i) {
        v.emplace_back(va[i]-1, vb[i]-1, (ll)vc[i]);
    }
    cout << sum - kruskal(v, n) << "\n";
    return 0;
}
