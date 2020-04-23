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
    vector<vector<pair<int, int>>> G(n);
    vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int p, q, r;
        cin >> p >> q >> r;
        G[r-1].emplace_back(p-1, q);
        in[p-1]++;
    }
    queue<int> v;
    for (int i = 0; i < n; ++i) {
        if(!in[i]) v.emplace(i);
    }
    vector<ll> dp(n, 0);
    dp[n-1] = 1;
    while(!v.empty()){
        int x = v.front(); v.pop();
        for (auto &&e : G[x]) {
            dp[e.first] += dp[x]*e.second;
            in[e.first]--;
            if(in[e.first] == 0){
                v.emplace(e.first);
            }
        }
        if(!G[x].empty()) dp[x] = 0;
    }
    for (int i = 0; i < n-1; ++i) {
        printf("%lld\n", dp[i]);
    }
    return 0;
}