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
    int t;
    cin >> t;
    while(t--){
        int n, a, b; string s;
        scanf("%d %d %d", &n, &a, &b); cin >> s;
        vector<ll> dp1(n+1, INF<ll>), dp2(n+1, INF<ll>);
        dp1[0] = b;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '0'){
                dp1[i+1] = min(dp1[i]+a+b, dp2[i]+2*a+b);
                dp2[i+1] = min(dp1[i]+2*a+2*b, dp2[i]+a+2*b);
            }else {
                dp2[i+1] = dp2[i]+a+2*b;
            }
        }
        printf("%lld\n", dp1[n]);
    }
    return 0;
}