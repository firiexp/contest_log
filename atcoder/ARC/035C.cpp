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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, INF<int>));
    for (int i = 0; i < n; ++i) {
        v[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int c, d, e;
        scanf("%d %d %d", &c, &d, &e);
        v[c-1][d-1] = v[d-1][c-1] = e;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int c, d, e;
        scanf("%d %d %d", &c, &d, &e);
        ll ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                v[j][k] = v[k][j] = min(v[k][j], e + min(v[k][c-1]+v[d-1][j], v[k][d-1]+v[c-1][j]));
                ans += v[j][k];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
