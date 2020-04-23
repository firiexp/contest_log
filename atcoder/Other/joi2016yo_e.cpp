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
    int n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;
    vector<vector<int>> G(n);
    queue<int> Q;
    vector<int> dist(n, INF<int>);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        x--;
        dist[x] = 0;
        Q.emplace(x);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        for (auto &&j : G[i]) {
            if(dist[j] > dist[i]+1){
                Q.emplace(j);
                dist[j] = dist[i]+1;
            }
        }
    }
    vector<vector<edge<ll>>> G2(n);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : G[i]) {
            if(!dist[j]) continue;
            if(j == n-1) G2[i].emplace_back(j, 0);
            else if(dist[j] <= s) G2[i].emplace_back(j, q);
            else  G2[i].emplace_back(j, p);
        }
    }
    auto ans = dijkstra(0, G2);
    cout << ans.back() << "\n";
    return 0;
}