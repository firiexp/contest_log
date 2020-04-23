#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    long double n, a, p = 0;
    cin >> n >> a;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        p += k;
    }
    cout << (fabs(p/n - a) < 1e-5 ? "YES\n" : "NO\n");
    return 0;
}
