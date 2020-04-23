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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if(m == n-1){
        ll ans = 0;
        deque<int> Q;
        vector<int> num(n);
        {
            stack<int> s;
            int cnt = 0;
            vector<int> visited(n, 0);
            s.emplace(0);
            while(!s.empty()){
                int a = s.top(); s.pop();
                visited[a]++;
                num[a] = cnt++;
                Q.emplace_front(a);
                for (auto &&i : G[a]) {
                    if(!visited[i]) s.emplace(i);
                }
            }
        }
        vector<int> dp(n);
        while(!Q.empty()){
            int i = Q.front(); Q.pop_front();
            dp[i] = 1;
            for (auto &&j : G[i]) {
                if(num[j] > num[i]){
                    dp[i] += dp[j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (auto &&j : G[i]) {
                if(i < j){
                    ll val = min(dp[i], dp[j]);
                    ans += val*(n-val);
                }
            }
        }
        cout << ans << "\n";
    } else if(n <= 3000 && m <= 3000){
        ll ans = 0;
        vector<int> d(n);
        queue<int> Q;
        for (int i = 0; i < n; ++i) {
            fill(d.begin(),d.end(), INF<int>);
            d[i] = 0;
            Q.emplace(i);
            while(!Q.empty()){
                int x = Q.front(); Q.pop();
                for (auto &&y : G[x]) {
                    if(d[x]+1 < d[y]){
                        d[y] = d[x]+1;
                        Q.emplace(y);
                    }
                }
            }
            ans += accumulate(d.begin(),d.end(), 0LL);
        }
        cout << ans/2 << "\n";
    }else assert(0);
    return 0;
}