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
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll c, m, x;
        scanf("%lld %lld %lld", &c, &m, &x);
        ll ok = 0, ng = INF<int>;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            ll cc = c, mm = m, xx = x;
            if(cc < mid || mm < mid){
                ng = mid;
                continue;
            }
            cc -= mid; mm -= mid;
            if(cc+mm+xx >= mid) ok = mid;
            else ng = mid;
        }
        printf("%lld\n", ok);
    }
    return 0;
}