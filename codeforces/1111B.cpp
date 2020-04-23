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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v(n);
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(),v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + v[i];
    }
    double ans = 0;
    for (ll i = n; i >= max(1, n-m); --i) {
        ans = max(ans, 1.0*(s[i]+min(m-(n-i), k*i))/i);
    }
    printf("%.10lf\n", ans);
    return 0;
}