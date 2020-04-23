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
    vector<int> a(n), b(n);
    ll ans = 0, ans1 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] == 0) ans += b[i];
        if((a[i]|k) == k) ans1 += b[i];
    }
    ans = max(ans, ans1);
    for (int i = 1 << 29; i; i >>= 1) {
        if((i & k) == 0) continue;
        ll tmp = 0;
        int mask = (k^i)|(i-1);
        for (int j = 0; j < n; ++j) {
            if((a[j]|mask) == mask) tmp += b[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
