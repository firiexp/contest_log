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
    int n;
    cin >> n;
    vector<int> v(n+1), u(n);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i]) {
            ans += min(v[i], u[i]);
            u[i] -= min(v[i], u[i]);
        }
        ans += min(v[i+1], u[i]);
        v[i+1] -= min(v[i+1], u[i]);
    }
    cout << ans << "\n";
    return 0;
}