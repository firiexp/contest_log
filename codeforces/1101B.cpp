#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    auto n = s.size();
    int k = 0, l = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        if(k == 0 && s[i] == '[') k++;
        if(k == 1 && s[i] == ':') k++, l = i;
    }
    if(k != 2) {
        puts("-1");
        return 0;
    }
    k = 0;
    for (int i = static_cast<int>(n - 1); i > l; --i) {
        if(k == 0 && s[i] == ']') k++;
        if(k == 1 && s[i] == ':') k++, m = i;
    }
    if(k != 2) {
        puts("-1");
        return 0;
    }
    int ans = 4;
    for (int i = l; i < m; ++i) {
        if(s[i] == '|') ans++;
    }
    cout << ans << "\n";
    return 0;
}
