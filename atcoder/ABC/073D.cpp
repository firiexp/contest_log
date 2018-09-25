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
    u32 n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> v(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        v[i][i] = 0;
    }
    vector<int> R(r);
    for (int i = 0; i < r; ++i) {
        int x;
        cin >> x;
        R[i] = x-1;
    }
    sort(R.begin(), R.end());
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a-1][b-1] = v[b-1][a-1] = c;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    do{
        ll x = 0;
        for (int i = 0; i < r - 1; ++i) {
            x += v[R[i]][R[i+1]];
        }
        ans = min(x, ans);
    }while(next_permutation(R.begin(), R.end()));
    cout << ans << "\n";
    return 0;
}
