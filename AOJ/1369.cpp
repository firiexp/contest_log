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
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    vector<pair<int, int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = {i, i+1};
    }
    for (int i = 0; i < m; ++i) {
        int x = v[i].second;
        pair<int, int> a {
            min(dp[x].first, dp[x-1].first), max(dp[x-1].second, dp[x].second)
        };
        dp[x] = dp[x-1] = a;
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", dp[i].second-dp[i].first);
    }
    puts("");
    return 0;
}