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
    ll r, b, x, y;
    cin >> r >> b >> x >> y;
    ll ok = 0, ng = INF<ll>/2;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(r < mid || b < mid){
            ng = mid;
            continue;
        }
        ll p = (r-mid)/(x-1)+(b-mid)/(y-1);
        (p >= mid ? ok : ng) = mid;
    }
    cout << ok << "\n";
    return 0;
}
