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
    int n;
    cin >> n;
    vector<ll> dp(6*n+1, 0);
    dp[0] = 1;
    for (int k = 0; k < 8; ++k) {
        for (int i = 6*n; i >= 0; --i) {
            for (int j = 1; j <= n && i+j <= 6*n; ++j) {
                dp[i+j] += dp[i];
            }
        }
    }
    cout << dp.back() << "\n";
    return 0;
}