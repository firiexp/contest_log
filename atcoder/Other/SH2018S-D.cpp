#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>> > &G){
    int n=G.size();
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;
    vector<T> d(n, INF);
    vector<int> b(n,-1);
    priority_queue<P,vector<P>,greater<> > Q;
    d[s]=0;
    Q.emplace(d[s],s);
    while(!Q.empty()){
        T cost;
        int i;
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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<edge<ll>>> vy(n), vs(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, a, b;
        scanf("%lld %lld %lld %lld", &u, &v, &a, &b);
        vy[u-1].emplace_back(v-1, a);
        vy[v-1].emplace_back(u-1, a);
        vs[u-1].emplace_back(v-1, b);
        vs[v-1].emplace_back(u-1, b);
    }
    vector<ll> cy = dijkstra(s-1, vy), cs = dijkstra(t-1, vs);
    for (int i = 0; i < n; ++i) {
        cy[i] += cs[i];
    }
    for (int i = n-2; i >= 0; --i) {
        cy[i] = min(cy[i], cy[i+1]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld\n", 1000000000000000-cy[i]);
    }
    return 0;
}
