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
    int n, m, s, g1, g2;
    while(cin >> n >> m >> s >> g1 >> g2, n){
        s--; g1--; g2--;
        vector<vector<ll>> G(n, vector<ll>(n, INF<int>));
        for (int i = 0; i < m; ++i) {
            int u, v, c; cin >> u >> v >> c;
            G[u-1][v-1] = c;
        }
        for (int i = 0; i < n; ++i) {
            G[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
        ll ans = G[s][g1]+G[s][g2];
        for (int i = 0; i < n; ++i) {
            ans = min(ans, G[s][i]+G[i][g1]+G[i][g2]);
        }
        cout << ans << "\n";
    }
    return 0;
}