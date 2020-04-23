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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n), Ginv(n);
    vector<int> d(n), d2(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].emplace_back(b, c);
        Ginv[b].emplace_back(a, c);
        d[b]++;
        d2[a]++;
    }
    vector<int> dp(n);
    stack<int> S;
    for (int i = 0; i < n; ++i) if(!d[i]) S.emplace(i);
    while(!S.empty()){
        int i = S.top(); S.pop();
        for (auto &&j : G[i]) {
            dp[j.first] = max(dp[j.first], dp[i]+j.second);
            d[j.first]--;
            if(!d[j.first]) S.emplace(j.first);
        }
    }
    vector<int> dp2(n, INF<int>);
    dp2.back() = dp.back();
    S.emplace(n-1);
    while(!S.empty()){
        int i = S.top(); S.pop();
        for (auto &&j : Ginv[i]) {
            dp2[j.first] = min(dp2[j.first], dp2[i]-j.second);
            d2[j.first]--;
            if(!d2[j.first]) S.emplace(j.first);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(dp[i] != dp2[i]) ans++;
    }
    printf("%d %d/%d\n", dp.back(), ans, n);
    return 0;
}