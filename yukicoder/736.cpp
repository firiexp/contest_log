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
    for (auto &&i : v) scanf("%lld", &i);
    auto p = static_cast<__uint128_t>(v[0]);
    for (int i = 1; i < n; ++i) {
        p = __gcd(p, static_cast<__uint128_t>(v[i]));
    }
    ll P = static_cast<ll>(p);
    for (auto &&j : v) j /= P;
    for (int i = 0; i < n; ++i) {
        if(i) cout << ":";
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
