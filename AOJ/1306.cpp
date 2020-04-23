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

void solve(int n){
    vector<int> p(n+1), t(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i+1] >> t[i+1];
    }
    vector<vector<int>> dp(n+1, vector<int>(4, INF<int>));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        for (int j = 0; j < 4; ++j) {
            if(dp[i][j] != INF<int>){
                if(j != 3){
                    if(t[i+1]-t[i] >= (j+1)*abs(p[i+1]-p[i])){
                        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(p[i+1]-p[i]));
                        ok = 1;
                    }
                }
                if(t[i+1]-t[i] >= (j+1)*p[i]+p[i+1]){
                    dp[i+1][1] = min(dp[i+1][1], dp[i][j]+p[i]+p[i+1]);
                    ok = 1;
                }
            }
        }
        if(!ok){
            printf("NG %d\n", i+1);
            return;
        }
    }
    int ans = INF<int>;
    for (int j = 0; j < 4; ++j) {
        ans = min(ans, dp.back()[j]);
    }
    printf("OK %d\n", ans+p.back());
}


int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}