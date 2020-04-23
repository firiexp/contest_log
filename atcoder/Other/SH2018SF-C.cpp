#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n), dp(n+1, 0), dp2(n+1, 0);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        if(i < k){
            dp2[i+1] = dp2[i] + v[i];
        }else{
            dp[i+1] = max(dp[i], dp2[i-k+1]);
            dp2[i+1] = max(dp[i], dp2[i]) + v[i];
        }
    }
    cout << max(dp[n], dp2[n]) << "\n";
    return 0;
}
