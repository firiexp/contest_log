#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    vector<int> c(n), d(n);
    int Q;
    cin >> Q;
    vector<array<int, 3>> x(Q);
    for (int i = 0; i < Q; ++i) {
        int s, t, u;
        cin >> s >> t >> u;
        x[i] = {s-1, t, u};
    }
    reverse(x.begin(), x.end());
    for (int i = 0; i < Q; ++i) {
        int v = x[i][0], p = x[i][1], q = x[i][2];
        queue<pair<int, int>> que;
        que.emplace(v, p);
        while(!que.empty()){
            int vv, pp; tie(vv, pp) = que.front(); que.pop();
            if(c[vv] == 0) c[vv] = q;
            if(d[vv] >= pp) continue;
            d[vv] = pp;
            for (auto &&j : G[vv]) {
                que.emplace(j, pp-1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", c[i]);
    }
    puts("");
    return 0;
}
