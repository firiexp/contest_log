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

int main() {
    int n, m, s, g;
    cin >> n >> m >> s >> g;
    vector<vector<int>> dist(n, vector<int>(n, INF<int>));
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[b][a] = dist[a][b] = c;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        sort(G[i].begin(),G[i].end());
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int cur = s;
    vector<int> ans{s};
    auto &&d = dist[g];
    while(cur != g){
        for (auto &&i : G[cur]) {
            if(d[i.first]+i.second == d[cur]){
                cur = i.first;
                ans.emplace_back(cur);
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}