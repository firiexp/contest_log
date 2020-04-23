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

template <typename T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

vector<int> ok;
template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>>> &G){
    auto n = G.size();
    vector<T> d(n, INF<T>);
    priority_queue<pair<T, int>,vector<pair<T, int>>,greater<>> Q;
    d[s] = 0;
    ok.resize(n);
    ok[s] = 1;
    Q.emplace(0, s);
    while(!Q.empty()){
        T cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] == cost2) ok[e.to] = 2;
            if(d[e.to] <= cost2) continue;
            ok[e.to] = 1;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge<int>>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[b].emplace_back(a, 1);
    }
    int k;
    cin >> k;
    vector<int> v(k);
    for (auto &&j : v) scanf("%d", &j), j--;
    auto d = dijkstra(v.back(), G);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < k-1; ++i) {
        if(d[v[i+1]]+1 != d[v[i]]) ans1++, ans2++;
        else if(ok[v[i]] == 2) ans2++;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}