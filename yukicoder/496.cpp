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
    int h, w, n, f;
    cin >> h >> w >> n >> f;
    vector<vector<int>> v(h+1, vector<int>(w+1, 0));
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            v[i][j] = f*(i+j);
        }
    }
    for (int q = 0; q < n; ++q) {
        int y, x, c;
        cin >> y >> x >> c;
        for (int i = h-y; i >= 0; --i) {
            for (int j = w-x; j >= 0; --j) {
                v[i+y][j+x] = min(v[i+y][j+x], v[i][j]+c);
            }
        }
    }
    cout << v[h][w] << "\n";
    return 0;
}