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

template<class T> T INF = 1000000000;

template <typename T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), r(n);
    auto f = [&](int i, int j){ return i*n+j; };
    vector<vector<edge<int>>> G(n);
    for (int i = 0; i < n; ++i) cin >> c[i] >> r[i];
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b, c[a]);
        G[b].emplace_back(a, c[b]);
    }
    vector<vector<int>> dp(n, vector<int>(n, INF<int>));
    priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<>> Q;
    dp[0][0] = 0;
    Q.emplace(0, 0, 0);
    while(!Q.empty()){
        int i, j, cost;
        tie(cost, i, j) = Q.top(); Q.pop();
        if(dp[i][j] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(dp[e.to][r[i]-1] <= cost2) continue;
            dp[e.to][r[i]-1] = cost2;
            Q.emplace(cost2, e.to, r[i]-1);
        }
        if(j){
            for (auto &&e : G[i]) {
                if(dp[e.to][j-1] <= cost) continue;
                dp[e.to][j-1] = cost;
                Q.emplace(cost, e.to, j-1);
            }
            if(dp[i][j-1] > cost) {
                dp[i][j-1] = cost;
                Q.emplace(cost, i, j-1);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[n-1][i]);
    }
    cout << ans << "\n";
    return 0;
}