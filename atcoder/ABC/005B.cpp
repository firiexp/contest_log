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
    int n;
    cin >> n;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ans = min(ans, k);
    }
    cout << ans << "\n";
    return 0;
}
