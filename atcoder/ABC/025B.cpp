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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int d;
        cin >> s >> d;
        if (d < a) d = a;
        if (b < d) d = b;
        if (s == "West") d = -d;
        ans += d;
    }
    if(ans == 0) cout << 0 << "\n";
    else cout << (ans > 0 ? "East" : "West" ) << " " << abs(ans) << "\n";
    return 0;
}
