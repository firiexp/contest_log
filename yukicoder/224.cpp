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
    int n, ans = 0;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
