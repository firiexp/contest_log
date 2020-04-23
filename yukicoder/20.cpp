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
    int n, v, ox, oy;
    cin >> n >> v >> ox >> oy;
    ox--; oy--;
    vector<vector<int>> c(n+2, vector<int>(n+2, INF<int>));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &c[i+1][j+1]);
        }
    }
    vector<vector<edge<int>>> G(n*n);
    array<int, 4> dy{1, -1, 0, 0}, dx{0, 0, -1, 1};
    auto f = [&](int i, int j){ return i*n+j; };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(f(i+dy[k], j+dx[k]) >= 0 && f(i+dy[k], j+dx[k]) < n*n){
                    G[f(i, j)].emplace_back(f(i+dy[k], j+dx[k]), c[i+dy[k]+1][j+dx[k]+1]);
                }
            }
        }
    }
    auto dist = dijkstra(0, G);
    if(dist.back() < v){
        puts("YES");
        return 0;
    }
    if(ox == -1){
        puts("NO");
        return 0;
    }
    auto dist2 = dijkstra(f(oy, ox), G);
    if(v-dist[f(oy, ox)] > 0 && dist2.back() < (v-dist[f(oy, ox)])*2){
        puts("YES");
    }else puts("NO");
    return 0;
}