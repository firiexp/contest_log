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
    cin >> s;
    int k = 0;
    for (int i = 0; i < 8; ++i) {
        cin >> t;
        for (auto &&j : t) {
            if(j != '.') k++;
        }
    }
    int p = (s == "oda");
    cout << (p^(k&1) ? "oda" : "yukiko") << "\n";
    return 0;
}
