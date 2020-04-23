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
    int m;
    while(cin >> m, m){
        vector<int> dp(1001);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            for (int j = 1000-a*(b+1); j >= 0; --j) {
                dp[j+a*(b+1)] -= dp[j];
            }
            for (int j = 0; j+a <= 1000; ++j) {
                dp[j+a] += dp[j];
            }
        }
        int g;
        cin >> g;
        for (int i = 0; i < g; ++i) {
            int a;
            cin >> a;
            cout << dp[a] << "\n";
        }
    }
    return 0;
}