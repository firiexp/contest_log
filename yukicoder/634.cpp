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
    ll n;
    cin >> n;
    ll ok = 0, ng = INF<int>;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if((mid+1)*mid/2 <= n) ok = mid;
        else ng = mid;
    }
    if((ok+1)*ok/2 == n){
        puts("1");
        return 0;
    }
    for (ll i = 1; i <= ok; ++i) {
        ll okk = 0, ngg = INF<int>;
        while(ngg-okk > 1){
            ll mid = (okk+ngg)/2;
            if((mid+1)*mid/2+(i+1)*i/2 <= n) okk = mid;
            else ngg = mid;
        }
        if((okk+1)*okk/2+(i+1)*i/2 == n){
            puts("2");
            return 0;
        }
    }
    puts("3");
    return 0;
}