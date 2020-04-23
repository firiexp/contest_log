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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto dp = make_v(30, n, 0LL);
    for (int i = 0; i < n; ++i) {
        dp[0][i] = v[i];
    }
    for (int i = 0; i < 29; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i+1][j] = dp[i][j] + dp[i][(j+dp[i][j])%n];
        }
    }
    for (int i = 0; i < n; ++i) {
        ll cur = i;
        for (int j = 0; j < 30; ++j) {
            if(k & (1 << j)){
                cur += dp[j][cur%n];
            }
        }
        printf("%lld\n", cur+1);
    }
    return 0;
}