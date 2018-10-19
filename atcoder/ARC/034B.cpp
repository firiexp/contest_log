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
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = max(1LL, n-300); i <= n; ++i) {
        ll p = i;
        for (auto &&j : to_string(i)) {
            p += j - '0';
        }
        if(p == n) v.emplace_back(i);
    }
    cout << v.size() << "\n";
    for (auto &&i : v) cout << i << "\n";
    return 0;
}
