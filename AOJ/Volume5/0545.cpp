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
    size_t n=G.size();
    using P = pair<T, int>;
    vector<T> d(n, INF<T>);
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
    int n, m;
    while(cin >> n >> m, n|m){
        vector<vector<edge<int>>> v(n);
        for (int i = 0; i < m; ++i) {
            int p, q;
            scanf("%d %d", &p, &q);
            v[p-1].emplace_back(q-1, 1);
            v[q-1].emplace_back(p-1, 1);
        }
        auto d = dijkstra(0, v);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if(d[i] <= 2) ans++;
        }
        cout << ans << "\n";
    }
    return 0;

}
