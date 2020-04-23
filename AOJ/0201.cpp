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

int main() {
    int n;
    while(cin >> n, n){
        int id = 0; map<string, int> M;
        vector<int> dp(n), dp2(n, INF<int>);
        for (int i = 0; i < n; ++i) {
            string s; int x;
            cin >> s >> x;
            dp[id] = x;
            M[s] = id++;
        }
        int m;
        cin >> m;
        vector<int> deg(n);
        vector<vector<int>> G(n);
        for (int i = 0; i < m; ++i) {
            string s; int a;
            cin >> s >> a;
            for (int j = 0; j < a; ++j) {
                string t; cin >> t;
                G[M[t]].emplace_back(M[s]);
                deg[M[s]]++;
            }
        }
        queue<int> Q;
        for (int i = 0; i < n; ++i) {
            if(!deg[i]) Q.emplace(i);
        }
        while(!Q.empty()){
            int i = Q.front(); Q.pop();
            for (auto &&j : G[i]) {
                if(dp2[j] == INF<int>) dp2[j] = min(dp[i], dp2[i]);
                else dp2[j] += min(dp[i], dp2[i]);
                deg[j]--;
                if(!deg[j]) Q.emplace(j);
            }
        }
        string s;
        cin >> s;
        cout << min(dp[M[s]], dp2[M[s]]) << "\n";
    }
    return 0;
}