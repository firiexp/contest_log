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
    string s;
    cin >> s;
    ll ans = 0;
    int n = static_cast<int>(s.length());
    ll a = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'B') a++;
        else ans += a;
    }
    cout << ans << "\n";
    return 0;
}
