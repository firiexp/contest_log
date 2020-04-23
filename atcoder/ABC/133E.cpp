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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    vector<int> dp(n);
    vector<int> par(n);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]){
                s.emplace(i);
                dp[i] = dp[a]+1;
                par[i] = a;
            }
        }
    }
    while(!Q.empty()){
        int a = Q.front(); Q.pop_front();
        for (auto &&b : G[a]){
            if(num[b] > num[a]){
                par[b] = a;
            }
        }
    }
    vector<int> dp2(n);
    ll ans = k;
    for (int i = 1; i < n; ++i) {
        int color = k-(min(dp[i], 2)+dp2[par[i]]);
        dp2[par[i]]++;
        if(color < 0) ans = 0;
        else (ans *= color) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}