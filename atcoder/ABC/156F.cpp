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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> d(n);
    for (auto &&i : d) scanf("%d", &i);
    while (q--) {
        int sz, x, mod;
        cin >> sz >> x >> mod;
        vector<int> dd(n), ok(n);
        for (int i = 0; i < n; ++i) {
            dd[i] = d[i] % mod;
            ok[i] = (dd[i] != 0);
        }
        ll loop = (sz-1)/n;
        ll dy = x%mod, ans = 0;
        for (int i = 0; i < n; ++i) {
            dy += (i < (sz-1)%n ? loop+1 : loop)*dd[i];
            ans += (i < (sz-1)%n ? loop+1 : loop)*ok[i];
        }
        cout << ans-dy/mod << "\n";
    }
    return 0;
}