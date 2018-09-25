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
    int n, sum = 0;
    cin >> n;
    vector<int> v1{0}, v2{0};
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        sum += k;
        v1.emplace_back(sum);
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        sum += k;
        v2.emplace_back(sum);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, v1[i]+v2[n]-v2[i-1]);
    }
    cout << ans << "\n";
    return 0;
}
