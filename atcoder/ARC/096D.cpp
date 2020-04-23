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
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n), S(n+1, 0), x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
        S[i+1] = S[i] + v[i];
    }
    ll ans = 0, a = 0, b = 0;
    for (ll i = n-1; i >= 0; --i) {
        ans = max({ans, S[i+1]-x[i]+a, S[i+1]-2*x[i]+b});
        a = max(a, S[n] - S[i] - 2*(c-x[i]));
        b = max(b, S[n]-S[i]-(c-x[i]));
    }
    cout << max(ans, b) << "\n";
    return 0;
}
