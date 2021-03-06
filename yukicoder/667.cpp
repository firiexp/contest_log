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
    for (auto &&i : s) {
        (i == 'o' ? a : b)++;
    }
    for (char i : s) {
        printf("%.12lf\n", (double)a/(a+b)*100);
        (i == 'o' ? a : b)--;
    }
    return 0;
}
