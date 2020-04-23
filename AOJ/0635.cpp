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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    using P = pair<int, int>;
    int N = n*2*(x+1);
    vector<vector<P>> G(N);
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        a--; b--;
        G[a].emplace_back(b, d);
        G[b].emplace_back(a, d);
    }
    auto f = [&x](int i, int j, int k){
        return i*2*(x+1) + j*(x+1) + k;
    };

    vector<int> d(N, INF<int>);
    priority_queue<P, vector<P>, greater<>> Q;
    d[f(0, 0, x)] = 0;
    Q.emplace(0, f(0, 0, x));
    while(!Q.empty()){
        int cost, i;
        tie(cost, i) = Q.top(); Q.pop();
        int a = i/(2*(x+1)), b = (i/(x+1)) & 1, c = i % (x+1);
        if(d[i] < cost) continue;
        auto update = [&](int x, int p) -> void{
            if(d[x] <= p) return;
            d[x] = p;
            Q.emplace(d[x], x);
        };
        for (auto &&e : G[a]) {
            int to, val; tie(to, val) = e;
            if(v[to] == 1){
                update(f(to, b, max(0, c-val)), cost+val);
            }else if(v[to] == 0) {
                if(b == 0 || max(0, c-val) == 0) update(f(to, 0, x), cost+val);
            }else {
                if(b == 1 || max(0, c-val) == 0) update(f(to, 1, x), cost+val);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= x; ++j) {
            ans = min(ans, d[f(n-1, i, j)]);
        }
    }
    cout << ans << "\n";
    return 0;
}