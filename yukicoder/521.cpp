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
    int ans = n;

    if(n-k+1 == k) ans += 1;
    ans -= 2;
    if(k == 0 || k > n) ans = 0;
    cout << ans << "\n";
    return 0;
}
