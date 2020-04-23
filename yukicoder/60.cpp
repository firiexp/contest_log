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

ll grid[1010][1010];
int main() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> E(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &E[i][j]);
        }
        E[i][0] += 500; E[i][1] += 500;
    }
    for (auto &&i : grid) {
        fill_n(i,1010, 0LL);
    }
    for (int i = 0; i < k; ++i) {
        int x, y, w, h, d;
        scanf("%d %d %d %d %d", &x, &y, &w, &h, &d);
        x += 500; y += 500;
        grid[x][y] += d;
        grid[min(1009, x+w+1)][min(1009, y+h+1)] += d;
        grid[x][min(1009, y+h+1)] -= d;
        grid[min(1009, x+w+1)][y] -= d;
    }
    for (int i = 1; i < 1010; ++i) {
        for (int j = 0; j < 1010; ++j) {
            grid[i][j] += grid[i-1][j];
        }
    }
    for (int i = 0; i < 1010; ++i) {
        for (int j = 1; j < 1010; ++j) {
            grid[i][j] += grid[i][j-1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(0LL, E[i][2]-grid[E[i][0]][E[i][1]]);
    }
    cout << ans << "\n";
    return 0;
}