#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 64 * 15 + 208;

int main() {
    ll n, t, q;
    cin >> n >> t >> q;
    vector<ll> v(n+2), u(n+2), ans(n+2, -INF<ll>);
    v[0] = -INF<ll>; u[0] = 1;
    v[n+1] = INF<ll>; u[n+1] = 2;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> u[i];
    }
    int l = 0, m = 1;
    ll tmp = 0;
    for (int i = 0; i <= n+1; ++i) {
        if(m == u[i]) continue;
        if(u[i] == 2){
            tmp = (v[i]+v[i-1])/2;
            m = 2;
        }else {
            for (int j = l; j <= i-1; ++j) {
                ans[j] = tmp;
            }
            l = i;
            m = 1;
        }
    }
    if(ans[n+1] == -INF<ll>) for (int j = l; j <= n+1; ++j) {
        ans[j] = tmp;
    }
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        if(abs(v[x]-ans[x]) < t) printf("%lld\n", ans[x]);
        else printf("%lld\n", v[x] + (v[x] > ans[x] ? -t : t));
    }
    return 0;
}
