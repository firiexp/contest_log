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
    vector<int> uni;
    int n;
public:
    multiset<int> s;
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n), s() {
        for (int i = 0; i < n; ++i) {
            s.emplace(1);
        }
    };

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        s.erase(s.find(-uni[a])); s.erase(s.find(-uni[b]));
        uni[a] += uni[b];
        s.insert(-uni[a]);
        uni[b] = a;
        return true;
    }
};


template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<edge<ll>> G;
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        scanf("%d %d %lld", &a, &b, &c); a--; b--;
        G.emplace_back(a, b, c);
    }
    sort(begin(G), end(G), [](const edge<ll> &a, const edge<ll> &b) { return (a.cost < b.cost); });
    UnionFind tree(n);
    vector<ll> ans(n+1, INF<ll>);
    ans[1] = 0;
    for (int i = 0; i < m; ++i) {
        const auto &e = G[i];
        tree.unite(e.from, e.to);
        chmin(ans[(*tree.s.begin())], e.cost);
    }
    for (int j = n - 1; j >= 0; --j) {
        chmin(ans[j], ans[j+1]);
    }
    for (int i = 0; i < q; ++i) {
        int X; scanf("%d", &X);
        if(X > n || ans[X] == INF<ll>) puts("trumpet");
        else printf("%lld\n", ans[X]);
    }
    return 0;
}