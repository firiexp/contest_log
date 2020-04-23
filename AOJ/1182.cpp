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

int dp[21][101][101];
int b[100000];
int main() {
    int n, m, c, s, g;
    while(cin >> n >> m >> c >> s >> g, n){
        s--; g--;
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[i][j][k] = INF<int>;
                }
                dp[i][j][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            int x, y, d, k;
            cin >> x >> y >> d >> k;
            x--; y--; k--;
            dp[k][x][y] = min(dp[k][x][y], d);
            dp[k][y][x] = min(dp[k][y][x], d) ;
        }
        for (int x = 0; x < c; ++x) {
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        dp[x][i][j] = min(dp[x][i][j], dp[x][i][k]+dp[x][k][j]);
                    }
                }
            }
        }
        vector<int> p(c);
        for (auto &&l : p) scanf("%d", &l);

        for (int i = 0; i < c; ++i) {
            vector<int> q(p[i], MOD), r(p[i], 0);
            for (int j = 0; j < p[i]-1; ++j) cin >> q[j];
            for (int j = 0; j < p[i]; ++j) cin >> r[j];
            int cur = 0;
            b[0] = 0;
            for (int j = 1; j < 100000; ++j) {
                if(q[cur] < j) cur++;
                b[j] = b[j-1] + r[cur];
            }
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if(dp[i][j][k] != INF<int>) dp[i][j][k] = b[dp[i][j][k]];
                }
            }
        }
        for (int i = 1; i < c; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[0][j][k] = min(dp[0][j][k], dp[i][j][k]);
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i][k]+dp[0][k][j]);
                }
            }
        }
        if(dp[0][s][g] == INF<int>){
            puts("-1");
        }else {
            cout << dp[0][s][g] << "\n";
        }
    }
    return 0;
}