#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    unsigned n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p, x, ans = 0;
        cin >> p >> x;
        for (int j = 1; j <= n; ++j) {
            ans += (p == j ? x : v[j-1]);
        }
        cout << ans << "\n";
    }
    return 0;
}
