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

int dp[52][52][52][52];
void solve(int h, int w){
    for(auto &i : dp) for(auto &j : i) for(auto &k : j) for(auto &l : k) l = INF<int>;
    int tx, ty, kx, ky;
    cin >> tx >> ty >> kx >> ky;
    vector<vector<int>> G(h+2, vector<int>(w+2, 1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> G[i+1][j+1];
        }
    }
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    queue<tuple<int, int, int, int>> Q;
    Q.emplace(ty, tx, ky, kx);
    dp[ty][tx][ky][kx] = 0;
    while(!Q.empty()){
        int y1, x1, y2, x2; tie(y1, x1, y2, x2) = Q.front(); Q.pop();
        if(dp[y1][x1][y2][x2] >= 100) break;
        if(y1 == y2 && x1 == x2){
            cout << dp[y1][x1][y2][x2] << "\n";
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int Y1 = y1+dy[k], X1 = x1+dx[k], Y2 = y2-dy[k], X2 = x2-dx[k];
            if(G[Y1][X1]) Y1 -= dy[k], X1 -= dx[k];
            if(G[Y2][X2]) Y2 += dy[k], X2 += dx[k];
            if(dp[Y1][X1][Y2][X2] > dp[y1][x1][y2][x2]+1){
                Q.emplace(Y1, X1, Y2, X2);
                dp[Y1][X1][Y2][X2] = dp[y1][x1][y2][x2]+1;
            }
        }
    }
    puts("NA");
}

int main() {
    int w, h;
    while(cin >> w >> h, w){
        solve(h, w);
    }
    return 0;
}