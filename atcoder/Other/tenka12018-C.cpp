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
    deque<int> q;
    vector<ll> v(n);
    for (auto &&j : v) scanf("%lld", &j);
    sort(v.begin(), v.end());
    ll p = v[n/2]+v[(n-1)/2], ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += llabs(v[i]*2-p);
    }
    if(n%2) ans -= min(v[n/2+1]-v[n/2], v[n/2]-v[n/2-1]);
    else ans -= v[n/2]-v[n/2-1];
    cout << ans << "\n";
    return 0;
}
