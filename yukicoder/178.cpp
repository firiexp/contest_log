#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll m = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v[i] = a+b*4;
        m = max(m, v[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if((m-v[i])%2) {
            puts("-1");
            return 0;
        }else ans += (m-v[i])/2;
    }
    cout << ans << "\n";
    return 0;
}
