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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    vector<ll> v(100050, INF<ll>), dp(100050, INF<ll>);
    for (int i = 0; i < n; ++i) {
        int b;
        scanf("%d",&b);
        v[i]=b;
    }
    dp[0]=0;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = min(dp[i+1], dp[i]+abs(v[i+1]-v[i]));
        dp[i+2] = min(dp[i+2], dp[i]+abs(v[i+2]-v[i]));
    }
    cout << dp[n-1] << "\n";
    return 0;
}
