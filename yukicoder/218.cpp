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
    int p = (a+b-1)/b, q = (a+c-1)/c;
    cout << (3*q <= 2*p ? "YES" : "NO") << "\n";
    return 0;
}
