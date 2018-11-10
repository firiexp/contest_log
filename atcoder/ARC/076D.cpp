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
    int n;
    cin >> n;
    vector<pair<int,int>> vx, vy;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        vx.emplace_back(x, i);
        vy.emplace_back(y, i);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vector<edge<ll>> G;
    G.reserve(2*n-2);
    for (int i = 0; i < n - 1; ++i) {
        G.emplace_back(vx[i].second, vx[i+1].second, (ll)(vx[i+1].first-vx[i].first));
        G.emplace_back(vy[i].second, vy[i+1].second, (ll)(vy[i+1].first-vy[i].first));
    }
    cout << kruskal(G, n) << "\n";
    return 0;
}
