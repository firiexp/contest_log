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
    int n, k, mx = -1, mn = 2000;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        mx = max(mx, p);
        mn = min(mn, p);
    }
    cout << mx-mn << "\n";
    return 0;
}
