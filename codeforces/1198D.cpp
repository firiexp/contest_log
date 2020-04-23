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

int dp[51][51][51][51];
int grid[51][51];

int sum(int y1, int x1, int y2, int x2){
    return grid[y2][x2] - grid[y2][x1] - grid[y1][x2] + grid[y1][x1];
}
template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i+1][j+1] = (s[j] == '#');
            dp[i][j][i+1][j+1] = (s[j] == '#');
        }
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j <= 50; ++j) {
            grid[i+1][j] += grid[i][j];
        }
    }
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            grid[i][j+1] += grid[i][j];
        }
    }
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            for (int k = i; k < 51; ++k) {
                for (int l = j; l < 51; ++l) {
                    dp[i][j][k][l] = (sum(i, j, k, l) ? max(k-i, l-j) : 0);
                }
            }
        }
    }
    for (int len1 = 1; len1 <= n; ++len1) {
        for (int len2 = 1; len2 <= n; ++len2) {
            if(len1 == 1 && len2 == 1) continue;
            for (int i = 0; i+len1 <= n; ++i) {
                for (int j = 0; j+len2 <= n; ++j) {
                    for (int k = i; k <= i+len1; ++k) {
                        chmin(dp[i][j][i+len1][j+len2],
                              dp[i][j][k][j+len2]+dp[k][j][i+len1][j+len2]);
                    }
                    for (int k = j; k <= j+len2; ++k) {
                        chmin(dp[i][j][i+len1][j+len2],
                              dp[i][j][i+len1][k]+dp[i][k][i+len1][j+len2]);
                    }

                }
            }
        }
    }
    cout << dp[0][0][n][n] << "\n";
    return 0;
}