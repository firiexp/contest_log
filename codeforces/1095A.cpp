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
    string s, ans;
    cin >> n >> s;
    for (int i = 0, j = 1; i < s.size(); i += j++) {
        ans += s[i];
    }
    cout << ans << "\n";
    return 0;
}