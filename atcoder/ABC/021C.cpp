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
    uint64_t n=G.size();
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;
    vector<T> d(n, INF);
    vector<int> b(n,-1);
    vector<T> numm(n, 0);
    fill(numm.begin(), numm.end(), 0);
    numm[s] = 1;
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
            if(d[e.to] < cost2) continue;
            if(d[e.to] == cost2){
                numm[e.to] = (numm[e.to] + numm[e.from]) % MOD;
                continue;
            }
            d[e.to] = cost2;
            numm[e.to] = numm[e.from];
            Q.emplace(d[e.to], e.to);
        }
    }
    return numm;
}

int main() {
    int n;
    int a, b;
    int m;
    cin >> n >> a >> b >> m;
    vector<vector<edge<int>>> v(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        v[x-1].emplace_back(x-1, y-1, 1);
        v[y-1].emplace_back(y-1, x-1, 1);
    }
    vector<int> v2 = dijkstra(a-1, v);
    cout << v2[b-1] << "\n";
    return 0;
}
