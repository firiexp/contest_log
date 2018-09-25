#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

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
    u32 n;
    cin >> n;
    vector<vector<edge<ll>>> v(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a-1].emplace_back(b-1, c);
        v[b-1].emplace_back(a-1, c);
    }
    int q, k;
    cin >> q >> k;
    vector<ll> d = dijkstra(k-1, v);
    for (int j = 0; j < q; ++j) {
        int x, y;
        scanf("%d %d", &x, &y);
        cout << d[x-1] + d[y-1] << "\n";
    }
    return 0;
}
