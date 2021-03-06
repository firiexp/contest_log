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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(i != 123) ans++;
    }
    cout << ans << "\n";
    return 0;
}
