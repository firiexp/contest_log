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
    vector<int> v(n+1, 1);
    vector<int> dp(n+1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v[x] = 0;
    }
    dp[0] = 1; dp[1] = v[1];
    for (int i = 2; i <= n; ++i) {
        if(v[i]) (dp[i] += dp[i-1]+dp[i-2]) %= MOD;
    }
    cout << dp.back() << "\n";
    return 0;
}