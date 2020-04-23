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

ll calc(ll d) {
    return (ll)((-1 + sqrt(1 + 4*d)) / 2.0);
}

ll calc2(ll d){
    ll ok = 0, ng = 2e9;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(mid*(mid+1) <= d) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    int cnt = 0;
    for (ll dd = 990000000; dd <= 1000000000 && cnt < 100000; ++dd) {
        for (int j = -5; j < 5; ++j) {
            ll d = dd*(dd+1)+j;
            if(calc(d) != calc2(d) && cnt < 100000) cnt++, cout << d << "\n";
        }
    }
    return 0;
}