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
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> v;
    vector<int> vv(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v[x] = i+1;
        vv[i] = x-1;
    }
    vector<vector<int>> G(n, vector<int>(k, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> G[i][j];
        }
    }
    vector<vector<int>> u(1<<m);
    for (int i = (1<<m)-1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            int to = 0;
            for (int l = 0; l < m; ++l) {
                if((i & (1<<l)) && v[G[vv[l]][j]]){
                    to |= (1 << (v[G[vv[l]][j]]-1));
                }
            }
            u[i].emplace_back(to);
        }
    }
    vector<int> dp(1<<m, MOD);
    queue<int> Q;
    Q.emplace((1<<m)-1);
    dp.back() = 0;
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        for (auto &&i : u[x]) {
            if(dp[x]+1 < dp[i]){
                dp[i] = dp[x]+1;
                Q.emplace(i);
            }
        }
    }
    cout << dp.front() << "\n";
    return 0;
}