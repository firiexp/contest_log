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
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n - 1; ++i) {
        ans += min(b, (v[i+1]-v[i])*a);
    }
    cout << ans << "\n";
    return 0;
}
