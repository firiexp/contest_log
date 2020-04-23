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
    ll ans = s.length()*(s.length()-1);
    for (int i = 1; i < s.length()-1; ++i) {
        if(s[i] == 'U') ans += i;
        else ans += s.length()-i-1;
    }
    cout << ans << "\n";
    return 0;
}
