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
    vector<int> v1(n), v2(n), v3(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v1[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &v2[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &v3[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (lower_bound(v1.begin(), v1.end(), v2[i])-v1.begin())*
                (lower_bound(v3.begin(), v3.end(), v2[i], greater<>())-v3.begin());
    }
    cout << ans << "\n";
    return 0;
}
