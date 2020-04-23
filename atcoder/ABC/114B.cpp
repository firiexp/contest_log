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
    int ans = INF<int>;
    string s;
    cin >> s;
    for (int i = 0; i < s.length()-2; ++i) {
        ans = min(ans, abs((s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0')-753));
    }
    cout << ans << "\n";
    return 0;
}
