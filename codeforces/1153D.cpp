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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 1; i < n; ++i) {
        int x;
        scanf("%d", &x);
        G[x-1].emplace_back(i);
        G[i].emplace_back(x-1);
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
    int ans = 0;
    vector<int> dp(n, 1);
    while(!Q.empty()){
        int c = 0; int a = Q.front(); Q.pop_front();
        for (auto &&i : G[a]) {
            if(num[i] > num[a]) c++;
        }
        if(c == 0) {
            ans++;
            continue;
        }
        if(v[a]){ // max
            dp[a] = INF<int>;
            for (auto &&i : G[a]) {
                if(num[i] > num[a]){
                    dp[a] = min(dp[a], dp[i]);
                }
            }
        }else {
            dp[a] = 0;
            for (auto &&i : G[a]) {
                if(num[i] > num[a]){
                    dp[a] += dp[i];
                }
            }
        }
    }
    cout << ans-dp[0]+1 << "\n";
    return 0;
}
