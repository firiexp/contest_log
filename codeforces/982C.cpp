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
    if(n%2){
        puts("-1");
        return 0;
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    vector<int> dp(n, 1);
    int ans = 0;
    auto dfs = [&](int i, int par, auto &&f) -> int {
        for (auto &&j : G[i]) {
            if(j != par){
                if(f(j, i, f)) dp[i] += dp[j];
            }
        }
        if((dp[i]&1) == 0) {
            ans++;
            return 0;
        }else {
            return 1;
        }
    };
    dfs(0, -1, dfs);
    cout << ans-1 << "\n";
    return 0;
}