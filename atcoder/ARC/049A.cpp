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
    int a, b, c, d;
    cin >> s >> a >> b >> c >> d;
    for (int i = 0; i < s.length(); ++i) {
        if(i == a || i == b || i == c || i == d) t += "\"";
        t += s[i];
    }
    if(s.length() == d) t += "\"";
    cout << t << "\n";
    return 0;
}
