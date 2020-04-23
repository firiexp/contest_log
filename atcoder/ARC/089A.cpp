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
    int t = 0, x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        int tt, xx, yy;
        scanf("%d %d %d", &tt, &xx, &yy);
        if((((tt-t)-(xx-x)-(yy-y))%2) || ((tt-t)-abs(xx-x)-abs(yy-y) < 0)) {
            cout << "No" << "\n";
            return 0;
        }
        t = tt, x = xx, y = yy;
    }
    cout << "Yes" << "\n";
    return 0;
}
