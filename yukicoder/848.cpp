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
    int n, m, p, q, t;
    cin >> n >> m >> p >> q >> t;
    p--; q--;
    vector<vector<edge<ll>>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    auto d1 = dijkstra(0, G), dp = dijkstra(p, G), dq = dijkstra(q, G);
    if(d1[p]+dp[q]+dq[0] <= t){
        cout << t << "\n";
        return 0;
    }else if(2*max(d1[q], d1[p]) > t){
        cout << -1 << "\n";
        return 0;
    }
    ll ans = INF<ll>;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(d1[i]+max(dp[i]+dp[j], dq[i]+dq[j])+d1[j] <= t){
                ans = min({ans, max(dp[i]+dp[j], dq[i]+dq[j])});
            }
        }
    }
    cout << max(-1LL, t-ans) << "\n";
    return 0;
}