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
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &&i : s) {
        m[i]++;
    }
    int a = INF<int>, b = 0;
    for (int i = '1'; i <= '4'; ++i) {
        a = min(m[i], a);
        b = max(m[i], b);
    }
    cout << b << " " << a << "\n";
    return 0;
}
