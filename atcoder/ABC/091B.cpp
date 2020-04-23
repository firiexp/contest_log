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
    int n, m;
    map<string, int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string k;
        cin >> k;
        v[k]++;
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
        string k;
        cin >> k;
        v[k]--;
    }
    int ans = 0;
    for (auto &&x : v) {
        ans = max(x.second, ans);
    }
    cout << ans << "\n";
    return 0;
}
