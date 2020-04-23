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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    vector<vector<int>> G(n);
    int ans = 0;
    if(v.front()) ans++;
    for (int i = 1; i < n; ++i) {
        G[i].emplace_back(v[i]);
        G[v[i]].emplace_back(i);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
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
    vector<int> dp(n, 1);
    while(!Q.empty()){
        int a = Q.front(); Q.pop_front();
        if(!a) continue;
        for (auto &&i : G[a]) {
            if(num[i] > num[a]){
                int p = dp[i]+1;
                if(p > k){
                    ans++;
                    p = 1;
                }
                dp[a] = max(dp[a], p);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
