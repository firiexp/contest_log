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
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>>> &G){
    auto n = G.size();
    vector<T> d(n, INF<T>);
    priority_queue<pair<T, int>,vector<pair<T, int>>,greater<>> Q;
    d[s] = 0;
    Q.emplace(0, s);
    while(!Q.empty()){
        T cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return d;
}

int main() {
    int x, y, z, n, m, s, t;
    cin >> x >> y >> z >> n >> m >> s >> t;
    vector<vector<edge<int>>> G(x+y+z+n+m);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(x+y+z+i, 1);
        G[x+y+z+i].emplace_back(a, 0);
        G[x+b].emplace_back(x+y+z+i, 1);
        G[x+y+z+i].emplace_back(x+b, 0);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[x+a].emplace_back(x+y+z+n+i, 1);
        G[x+y+z+n+i].emplace_back(x+a, 0);
        G[x+y+b].emplace_back(x+y+z+n+i, 1);
        G[x+y+z+n+i].emplace_back(x+y+b, 0);
    }
    auto dist = dijkstra(x+y+z+s-1, G);
    if(dist[x+y+z+n+t-1] == INF<int>) puts("-1");
    else cout << dist[x+y+z+n+t-1] << "\n";
    return 0;
}