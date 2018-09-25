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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int x, k;
    cin >> x >> k;
    int t = 1;
    for (int i = 0; i < k; ++i) t *= 10;
    cout << (x+t)/t*t << "\n";
    return 0;
}
