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
    for (int i = 1; i <= s.length(); ++i) {
        s[i-1] = static_cast<char>(((s[i - 1] - 'A' - i+260000) % 26) + 'A');
    }
    cout << s << "\n";
    return 0;
}
