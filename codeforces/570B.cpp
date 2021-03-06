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
    int n, m;
    cin >> n >> m;

    int ans = (n-m > m-1 ? m+1 : m-1);
    if(n == 1) ans = 1;
    cout << ans << "\n";
    return 0;
}
