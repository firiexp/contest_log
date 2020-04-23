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

static const int MOD = 998244353;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> ts(n-1), as(n-1), bs(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> ts[i] >> as[i] >> bs[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        vector<ll> dp(n+1);
        dp[0] = 1; cin >> dp[1];
        for (int j = 0; j < n-1; ++j) {
            if(ts[j] == 1){
                dp[j+2] = (dp[as[j]]+dp[bs[j]])%MOD;
            }else if(ts[j] == 2){
                dp[j+2] = (as[j]*dp[bs[j]])%MOD;
            }else {
                dp[j+2] = (dp[as[j]]*dp[bs[j]])%MOD;
            }
        }
        cout << dp.back() << "\n";
    }
    return 0;
}