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
    string s, t;
    cin >> s >> t;
    s += t;
    int p = 0, ans = 0;
    for (int i = 0; i < 14; ++i) {
        if(s[i] == 'o') p++;
        else {
            ans = max(ans, p);
            p = 0;
        }
    }
    ans = max(ans, p);
    cout << ans << "\n";
    return 0;
}
