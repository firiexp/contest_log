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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int g, r;
        scanf("%d %d", &g, &r);
        g--;
        for (int j = 0; j < r; ++j) {
            int x;
            scanf("%d", &x);
            x--;
            G[x].emplace_back(g);
            deg[g]++;
        }
    }
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        if(!deg[i]) Q.emplace(i);
    }
    int ans = 0;
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        ans++;
        for (auto &&j : G[i]) {
            deg[j]--;
            if(!deg[j]) Q.emplace(j);
        }
    }
    cout << ans << "\n";
    return 0;
}