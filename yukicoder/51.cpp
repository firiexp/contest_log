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
    int w, d;
    cin >> w >> d;
    for (int i = d; i >= 2; --i) {
        w -= w/i/i;
    }
    cout << w << "\n";
    return 0;
}
