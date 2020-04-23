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
    int t, u;
    cin >> s >> t >> u;
    for (int i = 0; i < s.length(); ++i) {
        if(i == t) continue;
        if(i == u) continue;
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
