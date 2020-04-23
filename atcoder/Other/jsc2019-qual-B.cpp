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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll ans1 = 0;
        for (int j = 0; j < i; ++j) {
            if(v[j] > v[i]) ans1++;
        }
        ll ans2 = 0;
        for (int j = 0; j < n; ++j) {
            if(v[j] > v[i]) ans2++;
        }
        (ans += k*(ans1*2%MOD+(k-1)*ans2%MOD)%MOD*500000004) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}