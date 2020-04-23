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
    ll n, k;
    cin >> n >> k;
    ll ans = (2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k;
    cout << ans << "\n";
    return 0;
}
