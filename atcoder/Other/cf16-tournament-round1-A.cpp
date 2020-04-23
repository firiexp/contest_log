#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

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

template<typename T>
vector<edge<T>> kruskal(vector<edge<T>> &G, int V) {
    sort(begin(G), end(G), [](const edge< T > &a, const edge< T > &b) { return (a.cost < b.cost); });
    UnionFind tree(V);
    vector<edge<T>> ret;
    for(auto &e : G) {
        if(tree.unite(e.from, e.to)) ret.emplace_back(e);
    }
    return (ret);
}

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    int n, m;
    cin >> n >> m;
    vector<edge<ll>> e;
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        scanf("%d %d %lli", &a, &b ,&c);
        a--; b--;
        e.emplace_back(a, b, c);
    }
    auto v = kruskal(e, n);
    auto cost = make_v(n, n, 0LL);
    ll S = 0;
    vector<vector<pair<int, ll>>> G(n);
    for (auto &&i : v) {
        S += i.cost;
        G[i.from].emplace_back(i.to, i.cost);
        G[i.to].emplace_back(i.from, i.cost);
    }
    for (int st = 0; st < n; ++st) {
        stack<int> s;
        vector<int> visited(n, 0);
        s.emplace(st);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            for (auto &&i : G[a]) {
                if(!visited[i.first]) {
                    s.emplace(i.first);
                    cost[st][i.first]
                        = max(cost[st][a], i.second);
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        cout << S-cost[s-1][t-1] << "\n";
    }
    return 0;
}
