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
    int ans = 1, x = s[0];
    for (int i = 1; i < s.length(); ++i) {
        if(s[i] <= x) ans++, x = s[i];
    }
    cout << ans << "\n";
    return 0;
}
