#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>


using ll = int64_t;
using u32 = uint32_t;
using namespace std;
static const ll MOD = static_cast<const ll>(1e12);

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll a = 1;
    ll n;
    cin >> n;
    bool f = false;
    for (int i = 1; i <= min(n, 50L); ++i) {
        if(a*i >= MOD) f = true;
        (a *= i) %= MOD;
    }
    printf(f ? "%012li" : "%li", a);
    return 0;
}
