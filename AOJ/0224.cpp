#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


bool solve(){
    int m, n, k, d;
    cin >> m >> n >> k >> d;
    if(!m) return 0;
    map<string, int> a;
    a["H"] = 0;
    for (int i = 0; i < m; ++i) a[string("C")+to_string(i+1)] = i+1;
    for (int i = 0; i < n; ++i) a[string("L")+to_string(i+1)] = i+m+1;
    a["D"] = n+m+1;
    vector<int> C(m);
    for (auto &&j : C) scanf("%d", &j);
    vector<vector<pair<int, int>>> G(n+m+2);
    for (int i = 0; i < d; ++i) {
        string S, T; int x;
        cin >> S >> T >> x;
        int s = a[S], t = a[T];
        G[s].emplace_back(t, x*k);
        G[t].emplace_back(s, x*k);
    }
    vector<int> dp((n+m+2) << m, INF<int>);
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> Q;
    dp[0] = 0;
    Q.emplace(0, 0);
    int mask = (1 << m)-1;
    while(!Q.empty()){
        int cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        int down = i & mask, up = i >> m;
        if(dp[i] < cost) continue;
        for (auto &&e : G[up]) {
            auto cost2 = cost + e.second;
            if(1 <= e.first && e.first <= m){
                if((1 << (e.first-1)) & i) continue;;
                int to = down | (1 << (e.first-1)) | (e.first << m);
                if(dp[to] <= cost2) continue;
                dp[to] = cost2;
                Q.emplace(dp[to], to);
            }else {
                int to = down | (e.first << m);
                if(dp[to] <= cost2) continue;
                dp[to] = cost2;
                Q.emplace(dp[to], to);
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < (1 << m); ++i) {
        int val = dp[(n+m+1) << m | i];
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                val -= C[j];
            }
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
    return 1;
}

int main() {
    while(solve());
    return 0;
}