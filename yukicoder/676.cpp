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
    string s = "IlOo", t = "1100", u;
    cin >> u;
    for (auto &&i : u) {
        for (int j = 0; j < 4; ++j) {
            if(i == s[j]) i = t[j];
        }
    }
    cout << u << "\n";
    return 0;
}
