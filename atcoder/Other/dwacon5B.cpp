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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n), S(n+1, 0);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
        s += v[i];
        S[i+1] = s;
    }
    vector<ll> vv;
    for (int i = n; i > 0; --i) {
        for (int j = 0; j < n-i+1; ++j) {
            vv.emplace_back(S[j+i]-S[j]);
        }
    }
    ll res = 0;
    for (ll l = 60; l >= 0; --l) {
        ll x = res + (1LL << l);
        int z = 0;
        for (auto &&i : vv) {
            if((x & i) == x) z++;
        }
        if(z >= k) res += x - res;
    }
    cout << res << "\n";
    return 0;
}
