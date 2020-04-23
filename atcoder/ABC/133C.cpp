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
    ll l, r;
    cin >> l >> r;
    if(r-l >= 2025){
        cout << 0 << "\n";
    }else {
        ll ans = 2019;
        for (ll i = l; i <= r; ++i) {
            for (ll j = i+1; j <= r; ++j) {
                ans = min(ans, i*j%2019);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}