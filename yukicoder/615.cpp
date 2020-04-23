#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%li", &i);
    sort(v.begin(), v.end());
    ll ans = v.back() - v.front();
    vector<ll> a(n-1);
    for (int i = 0; i < n-1; ++i) {
        a[i] = v[i+1]-v[i];
    }
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < k-1; ++i) {
         ans -= a[i];
    }
    cout << ans << "\n";
    return 0;
}
