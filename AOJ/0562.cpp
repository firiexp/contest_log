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

template<class T> T INF = 1000000007;

template <typename T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};



int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<edge<int>>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        G[a-1].emplace_back(b-1, l);
        G[b-1].emplace_back(a-1, l);
    }
    vector<int> d(n, INF<int>);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    for (int i = 0; i < k; ++i) {
        int t; cin >> t; t--;
        d[t] = 0;
        Q.emplace(0, t);
    }
    while(!Q.empty()){
        int cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    int ans = *max_element(d.begin(),d.end());
    for (int i = 0; i < n; ++i) {
        for (auto &&e : G[i]){
            if(d[e.to] < d[i] || d[e.to] == d[i]+e.cost) continue;
            ans = max(ans, (d[e.to]+d[i]+e.cost+1)/2);
        }
    }
    cout << ans << "\n";
    return 0;
}