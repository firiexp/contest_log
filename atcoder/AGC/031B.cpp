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
    int n;
    cin >> n;
    ll ans = 1;
    map<int, ll> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i : v) {
        ll ans2 = ans;
        (ans += m[i]) %= MOD;
        (m[i] += ans2) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
