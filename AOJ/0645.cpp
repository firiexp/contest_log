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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int>(w+2, -1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i+1][j+1];
        }
    }
    int n = h*w;
    vector<vector<edge<ll>>> G(n*n+n);
    auto f = [&n, &w](int i, int j, int k){ return i*(n+1)*w+j*(n+1)+k; };
    array<int, 4> dy{0, 0, -1, 1}, dx{1, -1, 0, 0};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i+dy[k]+1][j+dx[k]+1] != -1){
                    for (int l = 0; l < n; ++l) {
                        G[f(i, j, l)].emplace_back(
                                f(i+dy[k], j+dx[k], l+1),
                                (2*l+1)*v[i+dy[k]+1][j+dx[k]+1]);
                    }
                }
            }
        }
    }
    ll ans = INF<ll>;
    auto d = dijkstra(0, G);
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, d[f(h-1, w-1, i)]);
    }
    cout << ans << "\n";
    return 0;
}