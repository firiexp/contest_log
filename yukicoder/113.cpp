#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    int y = 0, x = 0;
    for (auto &&i : s) {
        if(i == 'N') y++;
        else if (i == 'S') y--;
        else if (i == 'E') x++;
        else x--;
    }
    cout << hypot(x, y) << "\n";
    return 0;
}
