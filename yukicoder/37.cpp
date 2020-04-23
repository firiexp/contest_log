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
    int t, n;
    cin >> t >> n;
    vector<int> c(n), v(n);
    for (auto &&i : c) scanf("%d", &i);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= t; ++j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            int S = v[i], p = v[i];
            for (int k = j+c[i]; k <= t && p > 0; k += c[i]) {
                dp[i+1][k] = max(dp[i+1][k], dp[i][j]+S);
                p /= 2;
                S += p;
            }
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}