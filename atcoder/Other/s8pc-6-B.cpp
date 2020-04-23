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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    auto aa = a, bb = b;
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    ll s = aa[(n-1)/2], t = bb[(n-1)/2];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += llabs(s-aa[i]) + llabs(aa[i]-bb[i]) + llabs(t-bb[i]);
    }
    cout << ans << "\n";
    return 0;
}
