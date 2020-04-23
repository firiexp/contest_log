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
    vector<int> dp(1<<n);
    for (int i = 1; i < (1<<n); ++i) {
        if((__builtin_popcount(i)&1) == 0){
            for (int j = 0; j < n; ++j) {
                if(!(i & (1 << j))) continue;
                for (int k = j+1; k < n; ++k) {
                    if(!(i & (1 << k))) continue;
                    dp[i] = max(dp[i], dp[i^(1<<j)^(1<<k)]+(v[j]^v[k]));
                }
            }
        }
    }
    cout << dp.back() << "\n";
    return 0;
}