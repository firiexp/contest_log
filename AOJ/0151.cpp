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


void solve(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%1d", &v[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(v[i][j]) cnt++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(v[j][i]) cnt++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
    }
    auto dp = v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i && j && dp[i][j]) dp[i][j] += dp[i-1][j-1];
            ans = max(ans, dp[i][j]);
        }
    }
    dp = v;
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= 0; --j) {
            if(i && j != n-1 && dp[i][j]) dp[i][j] += dp[i-1][j+1];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}