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
    int l, m, n;
    cin >> l >> m >> n;
    int p = 0;
    m += n/25;
    n = n%25;
    l += m/4;
    m = m%4;
    l = l % 10;
    cout << l+m+n << "\n";
    return 0;
}
