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
    ll k;
    cin >> k;
    ll x = 1;
    for (int i = 0; i <= 30; ++i) { // 0
        for (int j = 1; i+j <= 30; ++j) { // 1
            ll y = x*j*(j-1)/2;
            if(y == k){
                cout << i+j << "\n";
                for (int l = 0; l < i; ++l) cout << 0 << " ";
                for (int l = 0; l < j; ++l) cout << 1 << " ";
                cout << "\n";
                return 0;
            }
        }
        x *= 2;
    }
    return 0;
}
