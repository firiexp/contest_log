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
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

template <typename T>
vector<T> bellman_ford(int s, int N,vector<edge<T> > &G){
    vector<T> dist(N, INF<T>);
    vector<bool> negative(N);
    dist[s] = 0;
    for (int i = 0; i < N - 1; ++ i) {
        for (auto &&e : G) {
            if(dist[e.from] == INF<T>) continue;
            if(dist[e.to] > dist[e.from]+ e.cost){
                dist[e.to] = dist[e.from]+ e.cost;
            }
        }
    }
    ll ans = dist[N-1];
    for (int i = 0; i < N ; ++i) {
        for (auto &&e : G) {
            if(dist[e.from] == INF<T>) continue;
            if(dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if(negative[i]) dist[i] = -INF<T>;
    }
    return dist;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<edge<ll>> G;
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--; c = p-c;
        G.emplace_back(a, b, c);
    }
    auto ans = bellman_ford(0, n, G);
    if(ans.back() == -INF<ll>) puts("-1");
    else {
        cout << max(0LL, -ans.back()) << "\n";
    }
    return 0;
}