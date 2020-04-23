#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

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


int main() {
    uint64_t m, n;
    cin >> m >> n;
    uint64_t ans;
    if(m == 0) ans = n+1;
    else if(m == 1) ans = n+2;
    else if(m == 2) ans = 2*n+3;
    else ans = pow_(2UL, n+3, numeric_limits<uint64_t>::max())-3;
    cout << ans << "\n";
    return 0;
}
