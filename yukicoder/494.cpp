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
    string s, t = "yukicoder";
    cin >> s;
    for (int i = 0; i < t.length(); ++i) {
        if(s[i] != t[i]) cout << t[i] << "\n";
    }
    return 0;
}
