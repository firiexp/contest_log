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
    int l, h, n;
    cin >> l >> h >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(a < l) cout << l-a << "\n";
        else if (l <= a && a <= h) cout << 0 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
