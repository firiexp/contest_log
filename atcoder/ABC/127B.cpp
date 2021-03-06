#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll r, d, y;
    cin >> r >> d >> y;
    for (int i = 0; i < 10; ++i) {
        y = r*y-d;
        cout << y << "\n";
    }
    return 0;
}