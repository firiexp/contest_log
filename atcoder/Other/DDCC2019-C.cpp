#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>


using ll = long long;
using u32 = unsigned;
using namespace std;
static const ll MOD = 1000000007;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

ll p(ll k){
    return (pow_(k, 10LL, MOD)- pow_(k-1, 10LL, MOD) + MOD)%MOD;
}


int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; i*j <= n; ++j) {
            (ans += p(i)*p(j)) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
