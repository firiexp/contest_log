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
    vector<int> dp(1 << n), dp2(1 << n), cnt(1 << n);
    int s = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                dp[i] = dp[i^(1 << j)] + v[j];
                cnt[i] = cnt[i^(1 << j)]+1;
                if(dp[i] == k) dp2[(1 << n)-i-1] = -1, s++;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if(!(j & (1 << i))) dp2[j] += dp2[j|(1 << i)];
        }
    }
    int ans = 100;
    for (int i = 0; i < (1 << n); ++i) {
        if(dp2[i] == 0) ans = min(ans, cnt[i]);
    }
    cout << ans << "\n";
    return 0;
}