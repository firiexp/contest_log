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
    int mask1 = 0b00000001111111, mask2 = 0b11111110000000;
    cout << "?";
    for (int i = 0; i < 100; ++i) {
        cout << " " << i;
    }
    cout << endl;
    int ans1; cin >> ans1; ans1 &= mask2;
    cout << "?";
    for (int i = 1; i < 101; ++i) {
        cout << " " << (i << 7);
    }
    cout << endl;
    int ans2; cin >> ans2; ans2 &= mask1;
    cout << "! " << ans1+ans2 << endl;
    return 0;
}