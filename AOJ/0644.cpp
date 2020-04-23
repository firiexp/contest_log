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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + v[i];
    }
    int ans = INF<int>;
    for (int l = 0; l < n; ++l) {
        for (int r = l+1; r <= n; ++r) {
            if(r-l == n) continue;
            int m = S[r] - S[l];
            int M = m;
            if(l) {
                if(S[l]-S[0] < m) continue;
                vector<int> dp(l+1, INF<int>);
                dp[0] = 0;
                for (int i = 1; i <= l; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if(S[i]-S[j] >= m) dp[i] = min(dp[i], max(dp[j], S[i]-S[j]));
                    }
                }
                M = max(M, dp[l]);
            }
            if(r != n) {
                if(S[n]-S[r] < m) continue;
                vector<int> dp(n+1, INF<int>);
                dp[r] = 0;
                for (int i = r+1; i <= n; ++i) {
                    for (int j = r; j < i; ++j) {
                        if(S[i]-S[j] >= m) dp[i] = min(dp[i], max(dp[j], S[i]-S[j]));
                    }
                }
                M = max(M, dp[n]);
            }
            ans = min(ans, M-m);
        }
    }
    cout << ans << "\n";
    return 0;
}