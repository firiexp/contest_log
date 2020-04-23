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
    int a = 0, b = 0;
    for (int i = 1; i < s.length(); i += 5) {
        if(s[i] == '^') a++;
        else b++;
    }
    cout << a << " " << b << "\n";
    return 0;
}
