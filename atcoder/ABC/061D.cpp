#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
vector<T> bellman_ford(int s, int V,vector<edge<T> > &G){
    const T INF = numeric_limits<T>::max();
    vector<T> d(V, INF);
    d[s] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (auto &&e : G) {
            if (d[e.from] == INF) continue;
            if(d[e.to] == INF) d[e.to] = d[e.from] + e.cost;
            else d[e.to] = max(d[e.to], d[e.from] + e.cost);
        }
    }
    vector<T> d2 = d;
    for (int i = 0; i < V - 1; ++i) {
        for (auto &&e : G) {
            if (d[e.from] == INF) continue;
            if(d[e.to] == INF) d[e.to] = d[e.from] + e.cost;
            else d[e.to] = max(d[e.to], d[e.from] + e.cost);
        }
    }
    return d;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<edge<ll>> g;
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        g.emplace_back(a-1, b-1, c);
    }
    auto dists = bellman_ford(0, n, g);
    if(dists.empty()) cout << "inf\n";
    else cout << dists[n-1] << "\n";
}
