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
    int t, n;
    cin >> t >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<int, int>> dp(1 << n, {INF<int>, INF<int>});
    dp[0] = {0, 0};
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                int from = i ^ (1 << j);
                if(dp[from].second+v[j] > t){
                    dp[i] = min(dp[i], {dp[from].first+1, v[j]});
                }else {
                    dp[i] = min(dp[i], {dp[from].first, dp[from].second + v[j]});
                }
            }
        }
    }
    cout << dp.back().first+1 << "\n";
    return 0;
}