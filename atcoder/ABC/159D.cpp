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
    map<int, int> m;
    for (auto &&j : v) scanf("%d", &j), m[j]++;
    ll ans = 0;
    for (auto &&i : m) {
        ans += (ll)i.second*(i.second-1)/2;
    }
    for (int i = 0; i < n; ++i) {
        m[v[i]]--;
        ans -= m[v[i]];
        printf("%lld\n", ans);
        ans += m[v[i]];
        m[v[i]]++;
    }
    return 0;
}