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
    n = (n%4 == 0) + (n%100 == 0) + (n%400 == 0);;
    cout << (n%2 ? "YES\n" : "NO\n");
    return 0;
}
