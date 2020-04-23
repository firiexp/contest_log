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
    vector<long double> v{0.083333333333333, 0.166666666666667, 0.250000000000000,
                          0.083333333333333, 0.250000000000000, 0.166666666666667};
    vector<long double> dp(1000001, 1.0L);
    dp[0] = 0.0L;
    for (int i = 2; i <= 1000000; ++i) {
        for (int j = 0; j < min(i, 6); ++j) {
            dp[i] += dp[i-j-1]*v[j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        printf("%.15Lf\n", dp[n]);
    }
    return 0;
}