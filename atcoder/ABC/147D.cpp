#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> cnt(60);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        for (int j = 0; j < 60; ++j) {
            if(x & (1LL << j)){
                cnt[j]++;
            }
        }
    }
    ll ans = 0;
    ll t = 1;
    for (int i = 0; i < 60; ++i) {
        (ans += cnt[i]*(n-cnt[i])%MOD*t%MOD) %= MOD;
        (t *= 2) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}