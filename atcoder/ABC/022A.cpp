#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    u32 n, s, t;
    cin >> n >> s >> t;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());
    sort(v.begin(), v.end());
    int ans = upper_bound(v.begin(), v.end(),t)
            - lower_bound(v.begin(), v.end(), s);
    cout << ans << "\n";
    return 0;
}
