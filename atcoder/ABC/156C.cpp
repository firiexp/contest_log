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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    ll ans = INF<ll>;
    for (int i = 1; i <= 100; ++i) {
        ll val = 0;
        for (int j = 0; j < n; ++j) {
            val += (i-v[j])*(i-v[j]);
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
    return 0;
}