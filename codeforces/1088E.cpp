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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    if(*max_element(v.begin(),v.end()) <= 0){
        int x = *max_element(v.begin(),v.end()), c = count(v.begin(),v.end(), x);
        printf("%lld %d", (ll)x*c, c);
        return 0;
    }
    vector<ll> dp1(n), dp2(n);
    auto dfs = [&](int x, int par, auto &&f) -> ll {
        for (auto &&y : G[x]) {
            if(y == par) continue;
            dp1[x] += max(0LL, f(y, x, f));
        }
        return dp1[x] += v[x];
    };
    dfs(0, -1, dfs);
    ll val = *max_element(dp1.begin(),dp1.end());
    auto dfs2 = [&](int x, int par, auto &&f) -> int {
        int ans = 0;
        for (auto &&y : G[x]) {
            if(y == par) continue;
            ans += f(y, x, f);
            if(dp2[y] != val) dp2[x] += max(0LL, dp2[y]);
        }
        dp2[x] += v[x];
        return ans+(dp2[x] == val);
    };
    ll ans = dfs2(0, -1, dfs2);
    cout << ans*val << " " << ans << "\n";

    return 0;
}