#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

bool dp[2][20][20][1 << 10];

int main() {
    int h, w;
    array<int, 5> dy{-1, 1, 0, 0, 0}, dx{0, 0, -1, 1, 0};
    while(cin >> w >> h, w){
        vector<vector<int>> grid(h+2, vector<int>(w+2, -1));
        int sy = 0, sx = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c; cin >> c;
                if(c == 'P') sy = i, sx = j, grid[i+1][j+1] = 0;
                else if(c == '.') grid[i+1][j+1] = 0;
                else grid[i+1][j+1] = 1+(c-'0');
            }
        }
        int n;
        cin >> n;
        vector<int> gs(n), ds(n), ss(n), es(n);
        int M = 110;
        vector<int> id(11, -1);
        for (int i = 0; i < n; ++i) {
            cin >> gs[i] >> ds[i] >> ss[i] >> es[i];
            assert(id[gs[i]+1] == -1);
            id[gs[i]+1] = i;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < 1 << n; ++k) {
                    dp[0][i][j][k] = 0;
                }
            }
        }
        dp[0][sy][sx][0] = 1;
        for (int i = 0; i < M; ++i) {
            int now = i&1, nxt = now^1;
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < w; ++k) {
                    for (int l = 0; l < 1 << n; ++l) {
                        dp[nxt][j][k][l] = 0;
                    }
                }
            }
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < w; ++k) {
                    for (int d = 0; d < 5; ++d) {
                        if(grid[j+1+dy[d]][k+1+dx[d]]) continue;
                        for (int l = 0; l < (1 << n); ++l) {
                            if(!dp[now][j][k][l]) continue;
                            int l2 = l;
                            for (int dd = 0; dd < 4; ++dd) {
                                if(!~grid[j+1+dy[dd]][k+1+dx[dd]] || !~id[grid[j+1+dy[dd]][k+1+dx[dd]]]) continue;
                                int m = id[grid[j+1+dy[dd]][k+1+dx[dd]]];
                                if(!(l2 & (1 << m)) && ss[m] <= i && i < es[m]) {
                                    l2 |= (1 << m);
                                }
                            }
                            dp[nxt][j+dy[d]][k+dx[d]][l2] = 1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                for (int l = 0; l < (1 << n); ++l) {
                    if(!dp[M&1][j][k][l]) continue;
                    int val = 0;
                    for (int m = 0; m < n; ++m) {
                        if(l & (1 << m)) val += ds[m];
                    }
                    ans = max(ans, val);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}