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
    vector<int> dp(n);
    for (auto &&i : dp) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    deque<int> Q;
    stack<int> s;
    vector<int> visited(n, 0);
    s.emplace(0);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]) {
                s.emplace(i);
                if(dp[i]) dp[i] += dp[a];
            }
        }
    }
    fill(visited.begin(),visited.end(), 0);
    int ans = 0;
    while(!Q.empty()){
        int a = Q.back(); Q.pop_back();
        visited[a]++;
        for (auto &&i : G[a]) {
            if(!visited[i]) {
                dp[i] = max(dp[i], dp[a]);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if(dp[i] <= m && G[i].size() == 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}