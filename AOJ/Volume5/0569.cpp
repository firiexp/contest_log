#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w;
    cin >> w >> h;
    h += 2; w += 2;
    vector<vector<int>> v(h+2, vector<int>(w+2, -1));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            v[i][j] = 0;
        }
    }
    for (int i = 2; i <= h-1; ++i) {
        for (int j = 2; j <= w-1; ++j) {
            cin >> v[i][j];
        }
    }
    int dys[] = {-1, -1, 0, 0, 1, 1};
    int dx_odd[] = {-1, 0, -1, 1, -1, 0};
    int dx_even[] = {0, 1, -1, 1, 0, 1};
    stack<pair<int, int>> q;
    q.emplace(1, 1);
    while(!q.empty()){
        int y, x; tie(y, x) = q.top(); q.pop();
        v[y][x] = 2;
        for (int i = 0; i < 6; ++i) {
            int dy = dys[i], dx = (y&1 ? dx_odd : dx_even)[i];
            if(v[y+dy][x+dx] == 0) q.emplace(y+dy, x+dx);
        }
    }
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(v[i][j] != 2) continue;
            for (int k = 0; k < 6; ++k) {
                int dy = dys[k], dx = (i&1 ? dx_odd : dx_even)[k];
                if(v[i+dy][j+dx] == 1) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
