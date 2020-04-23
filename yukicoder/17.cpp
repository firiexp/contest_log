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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n, vector<int>(n, INF<int>));
    for (int i = 0; i < n; ++i) {
        G[i][i] = 0;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = min(G[a][b], c);
        G[b][a] = min(G[b][a], c);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    ll ans = INF<int>;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if(i == j) continue;
            ans = min(ans, (ll)G[0][i]+G[i][j]+G[j][n-1]+v[i]+v[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}