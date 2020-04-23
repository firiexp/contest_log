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

double dp[600];

double E(int n, vector<vector<int>> &G){
    for (int i = 0; i < n; ++i) {
        dp[i] = 0;
    }
    double ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n-1; ++i) {
        if(G[i].empty() && dp[i]) return INF<int>;
        for (auto &&j : G[i]) {
            ans += dp[i]/G[i].size();
            dp[j] += dp[i]/G[i].size();
        }
    }
    return ans;
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].emplace_back(t);
    }
    vector<double> dp2(n);
    dp2[n-1] = 1;
    for (int j = n - 1; j >= 0; --j) {
        for (auto &&i : G[j]) {
            dp2[j] += (dp2[i]+1)/G[j].size();
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(G[i].begin(),G[i].end(), [&](int x, int y){return dp2[x] < dp2[y]; });
    }
    double ans = E(n, G);
    for (int i = 0; i < n; ++i) {
        if(!G[i].empty()){
            int x = G[i].back(); G[i].pop_back();
            ans = min(ans, E(n, G));
            G[i].emplace_back(x);
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}