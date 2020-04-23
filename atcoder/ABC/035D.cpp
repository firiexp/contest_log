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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<vector<edge<ll>>> G(n), G2(n);
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        scanf("%d %d %lld", &a, &b, &c);
        G[a-1].emplace_back(b-1, c);
        G2[b-1].emplace_back(a-1, c);
    }
    auto d1 = dijkstra(0, G), d2 = dijkstra(0, G2);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {

        if(t > d1[i]+d2[i]) ans = max(ans, (t-d1[i]-d2[i])*v[i]);
    }
    cout << ans << "\n";
    return 0;
}