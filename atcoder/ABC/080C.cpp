#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;
using u32 = unsigned;

int main() {
    u32 n;
    int ans = -INF;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(10));
    vector<vector<int>> v2(n, vector<int>(11));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> v2[i][j];
        }
    }
    for (int i = 1; i < (1 << 10); ++i) {
        int pro = 0;
        vector<int> c(n, 0);
        c.assign(n, 0);
        for (int j = 0; j < 10; ++j) {
            if (i & (1<<j)) {
                for (int k = 0; k < n; ++k) {
                    if(v[k][j]==1) c[k]++;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            pro += v2[j][c[j]];
        }
        ans = max(ans, pro);
    }
    cout << ans << "\n";
    return 0;
}
