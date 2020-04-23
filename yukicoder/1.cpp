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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;
int main() {
    int n, c, v;
    cin >> n >> c >> v;
    auto dp = make_v(n, c+1, INF<int>);
    dp[0][0] = 0;
    using P = array<int, 3>;
    vector<vector<P>> G(n);
    vector<int> s(v), t(v), y(v), m(v);
    for (auto &&i : s) scanf("%d", &i);
    for (auto &&i : t) scanf("%d", &i);
    for (auto &&i : y) scanf("%d", &i);
    for (auto &&i : m) scanf("%d", &i);
    for (int i = 0; i < v; ++i) {
        G[s[i]-1].push_back(P{t[i]-1, y[i], m[i]});
    }
    GPQ<tuple<int, int, int>> Q;
    Q.emplace(0, 0, 0);
    while(!Q.empty()){
        int i, j, cost;
        tie(i, j, cost) = Q.top(); Q.pop();
        if(dp[i][j] < cost) continue;
        for (auto &&e : G[i]) {
            if(j+e[1] > c) continue;
            auto cost2 = cost + e[2];
            if(dp[e[0]][j+e[1]] <= cost2) continue;
            dp[e[0]][j+e[1]] = cost2;
            Q.emplace(e[0], j+e[1], dp[e[0]][j+e[1]]);
        }
    }
    int ans = *min_element(dp.back().begin(),dp.back().end());
    cout << (ans == INF<int> ? -1 : ans) << "\n";
    return 0;
}