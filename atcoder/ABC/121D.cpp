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

ll f(ll x) {
    if(x % 4 == 0) return x;
    if(x % 4 == 1) return 1;
    if(x % 4 == 2) return x+1;
    if(x % 4 == 3) return 0;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = f(b);
    if(a) ans ^= f(a-1);
    cout << ans << "\n";
    return 0;
}
