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
    int n, h, m, t;
    cin >> n >> h >> m >> t;
    ll p = h*60+m + (n-1)*t;
    p %= 1440;
    cout << p/60 << "\n" << p%60 << "\n";
    return 0;
}
