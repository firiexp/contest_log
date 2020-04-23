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
    vector<ll> dp(4001);
    dp[0] = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 2999; j >= 0; --j) {
            dp[j+1001] -= dp[j];
        }
        for (int j = 0; j < 4000; ++j) {
            dp[j+1] += dp[j];
        }
    }
    ll n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }
    return 0;
}