#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> pow2(n*n+1, 0);
    vector<ll> dp(n+1);
    pow2[0] = 1;
    for (int i = 1; i <= n*n; ++i) {
        pow2[i] = pow2[i-1]*2;
        while(pow2[i] >= MOD) pow2[i] -= MOD;
    }
    dp[0] = 1;
    for (int i = k+1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(i-k <= j){
                (dp[i] += dp[j]*(pow2[i-k]-1)) %= MOD;
            }else {
                ll y = (pow2[j+1]-1)*pow2[(i-j-k)*(i-j-k-1)/2] % MOD;
                (dp[i] += dp[j]*y) %= MOD;
            }
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
