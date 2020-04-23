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
    vector<int> v(2*n);
    for (auto &&j : v) scanf("%d", &j);
    vector<ll> ans1(n+1), ans2(n+1);
    for (int i = 0; i < n; ++i) {
        ans1[i+1] = v[2*i]-v[2*i+1];
        ans2[i] = v[2*i+1]-v[2*i];
    }
    for (int i = 0; i < n; ++i) {
        ans1[i+1] += ans1[i];
    }
    for (int i = n-1; i >= 0; --i) {
        ans2[i] += ans2[i+1];
    }
    ll ans = -INF<ll>;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, ans1[i]+ans2[i]);
    }
    cout << ans << "\n";
    return 0;
}