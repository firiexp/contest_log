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
    int n;
    while(cin >> n, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<vector<int>> grid(110, vector<int>(110, -1));
        for (int i = 0; i < 105; ++i) {
            for (int j = 0; j < 105; ++j) {
                grid[i+1][j+1] = MOD;
            }
        }
        queue<pair<int, int>> q;
        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                grid[i][j] = 0;
                q.emplace(i, j);
            }
        }
        array<int, 4> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};
        while(!q.empty()){
            int xx, yy; tie(xx, yy) = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                if((~grid[xx+dx[k]][yy+dy[k]]) && grid[xx][yy]+1 < grid[xx+dx[k]][yy+dy[k]]){
                    grid[xx+dx[k]][yy+dy[k]] = grid[xx][yy]+1;
                    q.emplace(xx+dx[k], yy+dy[k]);
                }
            }
        }
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int xx, yy;
            cin >> xx >> yy;
            ans += min(max(grid[x][y]-1, 0)+grid[xx][yy], abs(xx-x)+abs(yy-y));
            x = xx; y = yy;
        }
        cout << ans << "\n";
    }
    return 0;
}