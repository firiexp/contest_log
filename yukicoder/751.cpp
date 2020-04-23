#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll a = 1, b = 1, c = 1;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int x;
        cin >> x;
        if(x < 0) c *= -1, x *= -1;
        (i == 0 ? a : b) *= x;
        ll y = __gcd(a, b);
        a /= y; b /= y;
    }
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int x;
        cin >> x;
        if(x < 0) c *= -1, x *= -1;
        (i&1 ? a : b) *= x;
        ll y = __gcd(a, b);
        a /= y; b /= y;
    }
    cout << a*c << " " << b << "\n";
    return 0;
}
