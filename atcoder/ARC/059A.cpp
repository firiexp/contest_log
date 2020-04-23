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
    u32 n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    int ans1 = INF;
    for (int x = -100; x <= 100; ++x) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (v[i] - x) * (v[i] - x);
        }
        ans1 = min(ans, ans1);
    }
    cout << ans1 << "\n";
    return 0;
}
