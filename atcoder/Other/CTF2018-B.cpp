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
    ll x, y;
    cin >> x >> y;
    ll p = 3*y-x, q = 3*x-y;
    puts(
            (p%8 == 0 && q%8 == 0 && p >= 0 && q >= 0 )
            ? "Yes" : "No"
            );
    return 0;
}
