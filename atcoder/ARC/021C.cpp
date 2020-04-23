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
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n), d(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lli %lli", &a[i], &d[i]);
    }
    ll ng = 0, ok = 10000LL*k;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max(0LL, (mid-(a[i]-d[i]))/d[i]);
        }
        if(cnt >= k) ok = mid;
        else ng = mid;
    }
    uint64_t ans = 0;
    ll kk = 0;
    for (int i = 0; i < n; ++i) {
        ll p = max(0LL, (ok-(a[i]-d[i]))/d[i]);
        if(p%2) ans += (2LL*a[i]+(p-1)*d[i])/2*p;
        else ans += (2LL*a[i]+(p-1)*d[i])*(p/2);
        kk += p;
    }
    cout << ans-(kk-k)*ok << "\n";
    return 0;
}