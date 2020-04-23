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
    ll n;
    cin >> n;
    ll ans = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n/i; ++j) {
            ans = min(ans, n-i*j+abs(i-j));
        }
    }
    cout << ans << "\n";
    return 0;
}
