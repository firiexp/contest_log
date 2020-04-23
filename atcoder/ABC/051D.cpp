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
using P = pair<int, int>;


int main() {
    u32 n, m;
    cin >> n >> m;
    vector<vector<int> > d(n, vector<int>(n, INF));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = d[b-1][a-1] = c;
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    vector<vector<int> > d2 = d;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                d[j][k] = min(d[j][k], d[j][i]+ d[i][k]);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(d2[i][j] != INF && d2[i][j] != d[i][j]) cnt++;
        }
    }
    cout << cnt/2 << "\n";
    return 0;
}
