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
    ll n;
    cin >> n;
    string s = to_string(n);
    ll a = (s[0] - '0');
    for (int i = 0; i < (s.length()-1); ++i) {
        a *= 10;
    }
    a--;
    int ans = 0;
    for (auto &&j : to_string(a)) {
        ans += j - '0';
    }
    for (auto &&j : to_string(n-a)) {
        ans += j - '0';
    }
    cout << ans << "\n";
    return 0;
}
