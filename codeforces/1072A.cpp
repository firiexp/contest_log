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
    int w, h, k, ans = 0;
    cin >> w >> h >> k;
    for (int i = 0; i < k; ++i) {
        ans += (w-4*i)*(h-4*i);
        ans -= (w-4*i-2)*(h-4*i-2);
    }
    cout << ans << "\n";
    return 0;
}
