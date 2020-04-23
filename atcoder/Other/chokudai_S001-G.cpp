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
    ll ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> p = {1, 10, 100, 1000, 10000, 100000, 1000000};
    for (int i = 0; i < n; ++i) {
        (ans *= p[to_string(v[i]).size()]) %= MOD;
        ans += v[i];
    }
    cout << ans%MOD << "\n";
    return 0;
}