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
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<int>> v(h, vector<int>(w, 0));
    vector<int> x1(n, INF<int>), x2(n, -INF<int>),
                y1(n, INF<int>), y2(n, -INF<int>);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i][j]);
            if(v[i][j]){
                int k = v[i][j]-1;
                y1[k] = min(y1[k], i);
                y2[k] = max(y2[k], i);
                x1[k] = min(x1[k], j);
                x2[k] = max(x2[k], j);
            }
        }
    }
    vector<vector<int>> G(n);
    vector<int> deg(n), ans;
    for (int i = 0; i < n; ++i) {
        if(x1[i] == INF<int>) deg[i] = 10000;
        else {
            for (int j = y1[i]; j <= y2[i]; ++j) {
                for (int k = x1[i]; k <= x2[i]; ++k) {
                    if(v[j][k] != i+1 && v[j][k]){
                        G[v[j][k]-1].emplace_back(i);
                        deg[i]++;
                    }
                }
            }
        }
    }
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        if(!deg[i]) Q.emplace(i);
    }
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        ans.emplace_back(i+1);
        for (auto &&j : G[i]) {
            deg[j]--;
            if(!deg[j]) Q.emplace(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(deg[i]) ans.emplace_back(i+1);
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[n-i-1]);
    }
    puts("");
    return 0;
}