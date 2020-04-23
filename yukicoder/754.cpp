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
    vector<ll> a(n+1), b(n+1), S(n+2);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&i : b) scanf("%lld", &i);
    ll s = 0;
    for (int i = 0; i <= n; ++i) {
        (s += b[i]) %= MOD;
        S[i+1] = s;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        (ans += a[i]*S[n+1-i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
