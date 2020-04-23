#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &v[i], &v2[i]);
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    ll ans = n;
    for (int i = 0; i < n; ++i) {
        ans += max(v[i], v2[i]);
    }
    cout << ans << "\n";
    return 0;
}
