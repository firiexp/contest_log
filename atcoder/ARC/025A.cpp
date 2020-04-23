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
    int k[7], ans = 0;
    for (auto &&i : k) scanf("%d", &i);
    for (int &i : k) {
        int x;
        cin >> x;
        i = max(i, x);
        ans += i;
    }
    cout << ans << "\n";
    return 0;
}
