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
    int c, n;
    cin >> c >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> dp(c+1, INF<int>);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = v[i]; j <= c; ++j) {
            dp[j] = min(dp[j], dp[j-v[i]]+1);
        }
    }
    cout << (dp.back() == INF<int> ? -1 : dp.back());
    return 0;
}