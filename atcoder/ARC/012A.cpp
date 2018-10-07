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
    string s, t[] = {"Saturday", "Friday", "Thursday", "Wednesday", "Tuesday", "Monday"};
    cin >> s;
    for (int i = 0; i < 6; ++i) {
        if(t[i] == s)ans = i;
    }
    cout << ans << "\n";
    return 0;
}
