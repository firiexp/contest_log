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
    int n, x;
    cin >> n >> x;
    int k;
    cin >> k;
    int ans = abs(k-x);
    for (int i = 0; i < n-1; ++i) {
        int j;
        cin >> j;
        ans = __gcd(abs(j-k), ans);
        k = j;
    }
    cout << ans << "\n";
    return 0;
}
