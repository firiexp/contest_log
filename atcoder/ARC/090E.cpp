#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
pair<vector<T>, vector<T>> dijkstra(int s,vector<vector<edge<T>> > &G){
    size_t n=G.size();
    using P = pair<T, int>;
    vector<T> d(n, INF<T>);
    vector<T> ans(n, 0);
    vector<int> b(n,-1);
    priority_queue<P,vector<P>,greater<> > Q;
    d[s]=0;
    ans[s] = 1;
    Q.emplace(d[s],s);
    while(!Q.empty()){
        T cost;
        int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] == cost2) (ans[e.to] += ans[i]) %= MOD;
            if(d[e.to] <= cost2) continue;
            ans[e.to] = ans[i];
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return make_pair(d, ans);
}


int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<edge<ll>>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v; ll d;
        scanf("%d %d %li", &u, &v, &d);
        G[u-1].emplace_back(v-1, d);
        G[v-1].emplace_back(u-1, d);
    }
    vector<ll> d1, ans1, d2, ans2;
    tie(d1, ans1) = dijkstra(s, G);
    tie(d2, ans2) = dijkstra(t, G);
    ll ans = (ans1[t]*ans2[s]) % MOD;
    for (int i = 0; i < n; ++i) {
        if(d1[i] == d2[i] && d1[i] + d2[i] == d1[t]){
            ll x = (ans1[i]*ans2[i]) % MOD;
            (x *= x) %= MOD;
            (ans += MOD-x) %= MOD;
        }
    }
    for (int from = 0; from < n; ++from) {
        for (auto &&i : G[from]) {
            if(d1[from]+i.cost + d2[i.to] == d1[t] &&
               2*d1[from] < d1[t] && d1[t] < 2*d1[i.to]){
                ll x = (ans1[from]*ans2[i.to])%MOD;
                (x *= x) %= MOD;
                (ans += MOD- x) %= MOD;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
