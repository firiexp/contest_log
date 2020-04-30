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
    int M;
    while(cin >> M, M){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        vector<int> to(n+2);
        to.back() = n+1;
        for (int i = 0; i < n; ++i) {
            if(v[i] < 0) to[i+1] = max(0, i+1+v[i]);
            else to[i+1] = min(n+1, i+1+v[i]);
        }
        vector<vector<int>> dp(n+2, vector<int>(n+2, INF<int>));
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= M; ++j) {
                int t = to[min(n+1, i+j)];
                dp[i][t] = 1;
            }
        }
        for (int k = 0; k <= n+1; ++k) {
            for (int i = 0; i <= n+1; ++i) {
                for (int j = 0; j <= n+1; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        int ok = 1;
        for (int i = 0; i <= n; ++i) {
            if(dp[0][i] != INF<int> && dp[i][n+1] == INF<int>){
                ok = 0;
            }
        }
        puts(ok ? "OK" : "NG");
    }
    return 0;
}