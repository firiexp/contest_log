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
    ll s;
    cin >> s;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s += v[i];
    }
    sort(v.begin(), v.end());
    ll k = min(v[n/2], s/n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += llabs(k-v[i]);
    }
    cout << ans << "\n";
    return 0;
}
