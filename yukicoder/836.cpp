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
    ll l, r, n;
    cin >> l >> r >> n;
    vector<ll> a(n);
    l--;
    for (int i = 0; i < n; ++i) {
        if(r%n >= i) a[i] += r/n+1;
        else a[i] += r/n;
        if(l%n >= i) a[i] -= l/n+1;
        else a[i] -= l/n;
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld\n", a[i]);
    }
    return 0;
}