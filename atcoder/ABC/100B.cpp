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
    int d, n;
    cin >> d >> n;
    int ans = (n == 100 ? 101 : n);
    for (int i = 0; i < d; ++i) {
        ans *= 100;
    }
    cout << ans << "\n";
    return 0;
}
