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
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int j = 0; j < n; ++j) {
        if (x & (1<<j)) ans+= v[j];
    }
    cout << ans << "\n";
    return 0;
}
