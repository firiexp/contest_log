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
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> l(h, vector<int>(w, -MOD)),
                        r(h, vector<int>(w, MOD));
    while (n--) {
        int y, x, p;
        cin >> y >> x >> p;
        y--; x--;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int dist = abs(i-y)+abs(j-x);
                l[i][j] = max(l[i][j], p-dist);
                r[i][j] = min(r[i][j], p+dist);
                if(l[i][j] > r[i][j]){
                    puts("No");
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans += l[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}