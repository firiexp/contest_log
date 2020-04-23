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
    ll a, b, c;
    cin >> a >> b >> c;
    ll ng = 0, ok = INF<int>;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        ll k = mid*a+(mid/7)*b;
        (k >= c ? ok : ng) = mid;
    }
    cout << ok << "\n";
    return 0;
}
