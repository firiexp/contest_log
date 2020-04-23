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
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
    }
    ll ans = INF<ll>*2;
    for (int i = 0; i < n; ++i) {
        ll p = 1, val = 0;
        char a = 0;
        for (auto &&j : v[i]) {
            a = max(a, j);
        }
        ll x = (a >= 'A' ? 10+ a -'A' : a -'0')+1;
        for (char j : v[i]) {
            ll k = (j >= 'A' ? 10+ j -'A' : j -'0');
            val += p*k;
            p *= x;
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
    return 0;
}
