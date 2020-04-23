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
    int a, b, c;
    cin >> a >> b >> c;
    int k = abs(b)/b;
    a = abs(a), b = abs(b);
    cout << (a+c-1)/c +(b+c-1)/c + (a > 0 && k != -1) + (k == -1)*2 << "\n";
    return 0;
}
