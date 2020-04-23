#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int dfs(int h, int w, int depth, vector<vector<bool>> &grid){
    int ans = depth;
    for (int i = 0; i < 4; ++i) {
        if(grid[h+dy[i]][w+dx[i]]){
            grid[h][w] = false;
            ans = max(ans, dfs(h+dy[i], w+dx[i], depth+1, grid));
            grid[h][w] = true;
        }
    }
    return ans;
}


int main() {
    int w, h;
    while(cin >> w >> h, w|h){
        auto grid = make_v(h+2, w+2, false);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int x;
                cin >> x;
                grid[i+1][j+1] = (x == 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if(grid[i][j]) ans = max(ans, dfs(i, j, 1, grid));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
