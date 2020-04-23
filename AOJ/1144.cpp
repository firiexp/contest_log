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

namespace problem {
    array<array<int, 30>, 30> g, visited;
    int w, h;
    int gx, gy;
    array<int, 4> di{1, -1, 0, 0}, dj{0, 0, -1, 1};
    void dfs(int y, int x, int depth){
        if(depth > 10) return;
        for (int k = 0; k < 4; ++k) {
            int yy = y, xx = x;
            if(g[yy+di[k]][xx+dj[k]]) continue;
            while(!g[yy][xx]){
                visited[yy][xx] = min(visited[yy][xx], depth+1);
                yy += di[k]; xx += dj[k];
            }
            if(g[yy][xx] == 1){
                g[yy][xx] = 0;
                dfs(yy-di[k], xx-dj[k], depth+1);
                g[yy][xx] = 1;
            }
        }
    }
    void solve(int W, int H){
        w = W; h = H;
        for (int i = 0; i <= h+1; ++i) {
            for (int j = 0; j <= w+1; ++j) {
                g[i][j] = -1;
                visited[i][j] = INF<int>;
            }
        }
        int sx, sy;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> g[i][j];
                if(g[i][j] == 2) {
                    sy = i, sx = j;
                    g[i][j] = 0;
                }else if(g[i][j] == 3){
                    gy = i, gx = j;
                    g[i][j] = 0;
                }
            }
        }
        dfs(sy, sx, 0);
        cout << (visited[gy][gx] <= 10 ? visited[gy][gx] : -1) << "\n";
    }


}

int main() {
    int w, h;
    while(cin >> w >> h, w){
        problem::solve(w, h);
    }
    return 0;
}