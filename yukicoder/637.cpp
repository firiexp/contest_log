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
    int ans = 0;
    vector<int> v(5);
    for (auto &&i : v) cin >> i;
    for (auto &&i : v) {
        if((i%3) == 0) ans += 4;

        if((i%5) == 0) ans += 4;
        if((i%3)*(i%5)) ans += to_string(i).length();
    }
    cout << ans << "\n";
    return 0;
}
