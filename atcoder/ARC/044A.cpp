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
    cout << (((n%2 && n%3 && n%5 && n != 1) || (n == 2 || n == 3 || n == 5)) ? "Prime\n" : "Not Prime\n");
    return 0;
}
