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
    int h, w;
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy++; sx++; gy++; gx++;

    vector<vector<int>> grid(h+4, vector<int>(w+4, INF<int>)),
    dp(h+4, vector<int>(w+4, 0));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            grid[i+2][j+2] = (s[j]-'0');
        }
    }
    queue<tuple<int, int>> Q;
    Q.emplace(sy, sx);
    array<int, 4> dy{1, -1, 0, 0}, dx{0, 0, 1, -1};
    while(!Q.empty()){
        int y, x; tie(y, x) = Q.front(); Q.pop();
        if(dp[y][x]) continue;
        dp[y][x] = 1;
        for (int i = 0; i < 4; ++i) {
            if(abs(grid[y][x]-grid[y+dy[i]][x+dx[i]]) <= 1){
                Q.emplace(y+dy[i], x+dx[i]);
            }else if(grid[y][x] == grid[y+dy[i]*2][x+dx[i]*2] && grid[y][x] > grid[y+dy[i]][x+dx[i]]){
                Q.emplace(y+dy[i]*2, x+dx[i]*2);
            }
        }
    }
    puts(dp[gy][gx] ? "YES" : "NO");
    return 0;
}