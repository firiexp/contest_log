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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%li", &i);
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i]+v[i];
    }
    ll ans = INF<ll>;
    for (ll k = 1; k <= n; ++k) {
        int cnt = 0, cur = n;
        ll cost = x*(n+k);
        while(cur > 0){
            int cur2 = max((ll)0, cur-k);
            ll p = 5+max(cnt-1, 0)*2;
            cost += p*(s[cur]-s[cur2]);
            if(cost > ans){
                cost = ans;
                break;
            }
            cur = cur2; cnt++;
        }
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}
