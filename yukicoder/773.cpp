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
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = 23; i <= 25; ++i) {
        if(a > i || i > b) ans++;
    }
    cout << ans << "\n";
    return 0;
}
