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
    int n, k, ans = 1;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ans += (k < ans ? k : ans);
    }
    cout << ans << "\n";
    return 0;
}
