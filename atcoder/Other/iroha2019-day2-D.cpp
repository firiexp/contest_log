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
    T cost, num;

    edge(int to, T cost) : from(-1), to(to), cost(cost), num(-1) {}
    edge(int from, int to, T cost, T num) : from(from), to(to), cost(cost), num(num) {}

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
vector<T> kruskal(vector<edge<T>> &G, int V)
{
    sort(begin(G), end(G), [](const edge< T > &a, const edge< T > &b) { return (a.cost < b.cost); });
    UnionFind tree(V);
    vector<T> v;
    for(auto &e : G) {
        if(tree.unite(e.from, e.to)) v.emplace_back(e.num);
    }
    return v;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge<ll>> G;
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        G.emplace_back(a, b, -c, i+1);
    }
    auto k = kruskal(G, n);
    sort(k.begin(),k.end());
    for (auto &&j : k) {
        printf("%lld\n", j);
    }
    return 0;
}