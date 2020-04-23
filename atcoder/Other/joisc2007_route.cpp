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
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    vector<vector<ll>> X(n, vector<ll>(n, INF<ll>));
    for (int i = 0; i < n; ++i) {
        X[i][i] = 0;
    }
    vector<vector<edge<ll>>> G(n*n);
    for (int i = 0; i < m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        X[a][b] = c;
        X[b][a] = c;
    }
    auto f = [&n](int i, int j){ return i*n+j; };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(X[i][j] == INF<ll>) continue;
            for (int k = 0; k < n; ++k) {
                if(j == k || X[j][k] == INF<ll>) continue;
                if((xs[j]-xs[i])*(xs[j]-xs[k])+(ys[j]-ys[i])*(ys[j]-ys[k]) <= 0){
                    G[f(i, j)].emplace_back(f(j, k), X[j][k]);
                }
            }
        }
    }
    auto res = dijkstra(f(0, 0), G);
    ll ans = INF<ll>;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, res[f(i, 1)]);
    }
    cout << (ans == INF<ll> ? -1 : ans) << "\n";
    return 0;
}