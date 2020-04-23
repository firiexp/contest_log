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
using GPQ = priority_queue<T, vector<T>, greater<T>>;
using P = pair<int, int>;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dis(n, INF<int>);
    vector<map<int, int>> com(n);
    vector<vector<P>> G(n);
    for (int i = 0; i < m; ++i) {
        int p, q, c;
        scanf("%d %d %d", &p, &q, &c);
        G[p-1].emplace_back(q-1, c);
        G[q-1].emplace_back(p-1, c);
    }
    dis[0] = 0;
    GPQ<P> Q;
    Q.emplace(0, 0);
    while (!Q.empty()){
        int cost;
        int i;
        tie(cost, i) = Q.top(); Q.pop();
        i = -i;
        if(dis[i] < cost) continue;
        for (auto &&e : G[i]) {
            int cost2 = cost + (com[i][e.second] == 0);
            if(dis[e.first] < cost2) continue;
            if(dis[e.first] > cost2) {
                dis[e.first] = cost2;
                com[e.first].clear();
                Q.emplace(cost2, -e.first);
            }
            com[e.first][e.second]++;
        }
    }
    cout << (dis[n-1] >= INF<int> ? -1 : dis[n-1]*k) << "\n";
    return 0;
}
