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
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, k;
    cin >> n >> k;
    int a = n/2, b = 2*n - 1, c = 3*n - 1;
    vector<array<ll, 3>> t(n);
    for (int i = 0; i < n; ++i) {
        if (a + k + b + k > c + k) {
            puts("-1");
            return 0;
        }
        t[i] = {a + k, b + k, c + k};
        --c;
        if (a < b - 3) {
            ++a; b -= 2;
        } else {
            a = 0;
            b = 2 * n - 2;
        }
    }
    for (auto &&j : t) {
        printf("%lld %lld %lld\n", j[0], j[1], j[2]);
    }
    return 0;
}