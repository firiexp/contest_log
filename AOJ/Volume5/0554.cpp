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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = a+b+c+d;
    printf("%d\n%d\n", ans/60, ans%60);
    return 0;
}
