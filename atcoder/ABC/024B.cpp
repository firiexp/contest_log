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
    int n, t;
    cin >> n >> t;
    int a, ans = 0;
    cin >> a;
    for (int i = 0; i < n - 1; ++i) {
        int b;
        cin >> b;
        ans += min(t, b-a);
        a = b;
    }
    ans += t;
    cout << ans << "\n";
    return 0;
}
