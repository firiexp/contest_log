#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans += 2 * min(abs(a-k), a);
    }
    cout << ans << "\n";
    return 0;
}
