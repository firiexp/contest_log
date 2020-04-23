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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<vector<ll>> dp(n, vector<ll>{0});
    vector<ll> h(n, INF<ll>);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d %lli", &p, &h[i]);
        v[i].emplace_back(p);
        v[p].emplace_back(i);
    }
    deque<int> Q;
    vector<int> visited(n, 0), num(n);
    {
        stack<int> s;
        int cnt = 0;
        s.emplace(0);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            Q.emplace_front(a);
            for (auto &&i : v[a]) {
                if(!visited[i]) s.emplace(i);
            }
        }
    }
    while(!Q.empty()){
        int i = Q.front(); Q.pop_front();
        for (auto &&j : v[i]) {
            if(num[i] > num[j]) continue;
            vector<ll> dq(dp[i].size()+dp[j].size(), INF<ll>);
            for (int k = 0; k < dp[i].size(); ++k) {
                for (int l = 0; l < dp[j].size(); ++l) {
                    chmin(dq[k+l], dp[i][k]+dp[j][l]);
                }
            }
            dp[i] = dq;
        }
        while(dp[i].back() > h[i]) dp[i].pop_back();
        dp[i].emplace_back(h[i]);
    }
    int ans = 0;
    for (int i = 0; i < dp[0].size(); ++i) {
        if(dp[0][i] != INF<ll>) chmax(ans, i);
    }
    cout << ans+1 << "\n";
    return 0;
}