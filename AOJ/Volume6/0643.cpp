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

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> m(h, vector<int> (w, 0));
    int ans = INF<int>;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int u = 0;
            for (int k = 0; k < h; ++k) {
                for (int l = 0; l < w; ++l) {
                    u += m[k][l] * min(abs(k-i), abs(l-j));
                }
            }
            ans = min(ans, u);
        }
    }
    cout << ans << "\n";
    return 0;
}
