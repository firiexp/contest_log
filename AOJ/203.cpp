#include <iostream>
#include <algorithm>
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
    int h, w;
    while(cin >> w >> h, w){
        vector<vector<int>> G(h+2, vector<int>(w+2, 1));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> G[i+1][j+1];
            }
        }
        vector<vector<int>> dp(h+2, vector<int>(w+2, 0));
        for (int i = 0; i < w; ++i) {
            if(G[1][i+1] != 1) dp[1][i+1] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if(i == h) ans += dp[i][j];
                else if(G[i][j] == 0){
                    for (int k = -1; k <= 1; ++k) {
                        if(G[i+1][j+k] == 0) dp[i+1][j+k] += dp[i][j];
                        else if(G[i+1][j+k] == 2 && !k) dp[i+1][j] += dp[i][j];
                    }
                }else if(G[i][j] == 2){
                    if(i >= h-1) ans += dp[i][j];
                    else if(G[i+2][j] != 1) dp[i+2][j] += dp[i][j];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}