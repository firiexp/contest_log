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
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    cout << l-max((a+c-1)/c, (b+d-1)/d) << "\n";
    return 0;
}
