#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;
/* initialize */
int n;
vector<pair<int, int> > adj[10000];

void dijkstra(){
    priority_queue<pair<int,int> > PQ;
    int color[10000];
    int d[10000];
    for (int i = 0; i < n; ++i) {d[i] = INT32_MAX; color[i] = 0;};
    d[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = 1;
    while (!PQ.empty()){
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        color[u] = 2;
        if (d[u] < f.first * (-1)) continue;

        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].first;
            if(color[v] == 2) continue;
            if (d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v]*-1, v));
                color[v] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i << " " << (d[i] == INT32_MAX ? -1 : d[i]) << "\n";
    }
};
/* main */
int main() {
    int k, u, v, c;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d %d", &v, &c);
            adj[u].emplace_back(v,c);
        }
    }
    dijkstra();
    return 0;
}