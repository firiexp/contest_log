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
    for (auto &&i : v) scanf("%d", &i);
    map<int, ll> m;
    for (int i = 0; i < n; ++i) {
        v[i] -= i;
        m[v[i]] += v[i]+i;
    }
    ll ans = 0;
    for (auto &&j : m) {
        ans = max(ans, j.second);
    }
    cout << ans << "\n";
    return 0;
}