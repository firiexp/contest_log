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
    for (int i = 1; i < n; ++i) {
        int x = 0;
        string s = to_string(i), t = to_string(n - i);
        for (auto &&c : s) x += c - '0';
        for (auto &&c : t) x += c - '0';
        ans = min(ans, x);
    }
    cout << ans << "\n";
    return 0;
}
