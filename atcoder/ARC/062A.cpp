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
    ll mx = 1, my = 1;
    int n;
    cin >> n;
    cin >> mx >> my;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        ll k = max((mx+x-1)/x ,(my+y-1)/y);
        mx = k * x, my = k * y;
    }
    cout << mx + my << "\n";
    return 0;
}
