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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        int w, h;
        cin >> w >> h;
        vector<vector<int>> v(h+1, vector<int>(w+1, 0));
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            v[y][x]++;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j <= w; ++j) {
                v[i+1][j] += v[i][j];
            }
        }
        for (int i = 0; i <= h; ++i) {
            for (int j = 0; j < w; ++j) {
                v[i][j+1] += v[i][j];
            }
        }
        int s, t;
        cin >> t >> s;
        int ans = 0;
        for (int i = 0; i <= h-s; ++i) {
            for (int j = 0; j <= w-t; ++j) {
                ans = max(ans, v[i+s][j+t]-v[i][j+t]-v[i+s][j]+v[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
