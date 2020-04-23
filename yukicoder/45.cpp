#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n+1);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = v[i];
        dp[i+1] = max(dp[i+1], dp[i]);
        if(i >= 1) dp[i+1] = max(dp[i+1], dp[i-1]+v[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}
