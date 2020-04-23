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
    int n, c;
    cin >> n >> c;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n-1; ++i) {
        int x;
        scanf("%d", &x);
        a[i+1] = a[i] + x;
    }
    for (int i = 0; i < n-1; ++i) {
        int x;
        scanf("%d", &x);
        b[i+1] = b[i] + x;
    }
    vector<ll> dp(n, INF<ll>);
    dp[0] = 0;
    ll ans1 = 0, ans2 = c;

    for (int i = 0; i < n-1; ++i) {
        dp[i+1] = min(a[i+1]+ans1, b[i+1]+ans2);
        ans1 = min(ans1, dp[i+1]-a[i+1]);
        ans2 = min(ans2, dp[i+1]+c-b[i+1]);
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", dp[i]);
    }
    puts("");
    return 0;
}