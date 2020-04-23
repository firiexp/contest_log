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
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll n;
        scanf("%lld", &n);
        if(i) printf(" ");
        if(n <= 2){
            printf("%lld", n);
        }else if(n%3 == 0){
            printf("%lld", pow_(3LL, n/3, (ll)MOD));
        }else if(n%3 == 1){
            printf("%lld", pow_(3LL, n/3-1, (ll)MOD)*4%MOD);
        }else {
            printf("%lld", pow_(3LL, n/3, (ll)MOD)*2%MOD);
        }
    }
    puts("");
    return 0;
}