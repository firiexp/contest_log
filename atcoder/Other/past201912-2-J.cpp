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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h+2, w+2, INF<int>);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i+1][j+1];
        }
    }
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    vector<vector<edge<int>>> G(h*w);
    auto f = [&](int x, int y){return x*w+y; };
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i+1+dy[k]][j+1+dx[k]] != INF<int>){
                    G[i*w+j].emplace_back(f(i+dy[k], j+dx[k]), v[i+1+dy[k]][j+1+dx[k]]);
                }
            }
        }
    }
    auto dist1 = dijkstra(f(h-1, 0), G);
    auto dist2 = dijkstra(f(0, w-1), G);
    auto dist3 = dijkstra(f(h-1, w-1), G);
    int ans = INF<int>;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = min(ans, dist1[f(i, j)]+dist2[f(i, j)]+dist3[f(i, j)]-2*v[i+1][j+1]);
        }
    }
    cout << ans << "\n";
    return 0;
}