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
    vector<pair<int, int>> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(),v.end());
    vector<int> l1(n+1, -INF<int>), r1(n+1, INF<int>), l2(n+1, -INF<int>), r2(n+1, INF<int>);
    for (int i = 0; i < n; ++i) {
        l1[i+1] = max(l1[i], v[i].second); r1[i+1] = min(r1[i], v[i].first);
    }
    for (int i = n - 1; i >= 0; --i) {
        l2[i] = max(l2[i+1], v[i].second); r2[i] = min(r2[i+1], v[i].first);
    }
    for (int i = 1; i < n; ++i) {
        ans = max(ans, max(r1[i]-l1[i]+1, 0)+max(r2[i]-l2[i]+1, 0));
    }
    for (int i = 0; i < n; ++i) {
        int lx = max(l1[i], l2[i+1]), rx = min(r1[i], r2[i+1]);
        ans = max(ans, max(rx-lx+1, 0)+v[i].first-v[i].second+1);
    }
    cout << ans << "\n";
    return 0;
}