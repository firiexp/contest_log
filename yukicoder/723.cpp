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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    map<int, ll> m;
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), m[i]++;
    for (int i = 0; i < n; ++i) ans += m[x-v[i]];
    cout << ans << "\n";
    return 0;
}
