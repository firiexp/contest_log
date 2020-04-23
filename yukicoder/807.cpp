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
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>>> &G){
    size_t n=G.size();
    vector<T> d(n, INF<T>);
    priority_queue<pair<T, int>,vector<pair<T, int>>,greater<>> Q;
    d[s]=0;
    Q.emplace(0,s);
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
    int n, m;
    cin >> n >> m;
    vector<vector<edge<ll>>> G(2*n);
    for (int i = 0; i < m; ++i) {
        int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
        a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
        G[a].emplace_back(b+n, 0);
        G[b].emplace_back(a+n, 0);
        G[a+n].emplace_back(b+n, c);
        G[b+n].emplace_back(a+n, c);
    }
    auto dist = dijkstra(0, G);
    puts("0");
    for (int i = 1; i < n; ++i) {
        printf("%lld\n", dist[i]+dist[i+n]);
    }
    return 0;
}