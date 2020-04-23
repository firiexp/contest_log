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
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    int q;
    cin >> q;
    vector<int> c(n, -1), d(n);
    for (int i = 0; i < q; ++i) {
        queue<pair<int, int>> Q;
        int x;
        scanf("%d", &x);
        Q.emplace(x, 2);
        ll ans = 0;
        while(!Q.empty()){
            int vv, pp; tie(vv, pp) = Q.front(); Q.pop();
            if(c[vv] < i) {
                ans += v[vv];
                c[vv] = i;
            }
            if(d[vv] >= pp) continue;
            d[vv] = pp;

            for (auto &&j : G[vv]) {
                Q.emplace(j, pp-1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}