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
    ll n, sum1 = 1, sum2 = 0, r = 1;
    cin >> n;
    for (ll i = 2; i <= n; ++i) {
        if(i&1) {
            r = (i*sum2) % MOD;
            (sum1 += r) %= MOD;
        }else {
            r = (i*sum1) % MOD;
            (sum2 += r) %= MOD;
        }
    }
    cout << r << "\n";
    return 0;
}
