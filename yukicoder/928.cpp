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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll p, q, a;
    cin >> p >> q >> a;
    ll ans = 0;
    if(a == 0 && p == q){
    } else if(a == 0 && p <= q){
        ans = 1000000000;
        for (ll i = 1; i <= 100000000; ++i) {
            if(p*i/100 >= q*i/100 + a) ans--;
        }
    }else if(p <= q){
        cout << 1000000000 << "\n";
        return 0;
    }else {
        for (ll i = 1; i <= 100000000; ++i) {
            if(p*i/100 < q*i/100 + a) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}