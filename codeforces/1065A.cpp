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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        ll ans = s/c;
        ans += ans/a*b;
        cout << ans << "\n";
    }
    return 0;
}
