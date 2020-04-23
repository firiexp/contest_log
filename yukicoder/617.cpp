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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < (1 << n); ++i) {
        int w = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) {
                w += v[j];
            }
        }
        if(w <= k) ans = max(ans, w);
    }
    cout << ans << "\n";
    return 0;
}
