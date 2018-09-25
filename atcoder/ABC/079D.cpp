#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> v[i][j];
        }
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    vector<int> cost(10);
    for (int i = 0; i < 10; ++i) {
        cost[i] = v[i][1];
    }
    ll ans = 0;
    for (int i = 0; i < h*w; ++i) {
        int x;
        scanf("%d", &x);
        if(x != -1) ans += cost[x];
    }
    cout << ans << "\n";
    return 0;
}
