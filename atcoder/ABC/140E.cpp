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
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(),v.end(), greater<>());
    ll ans = 0;
    set<int> s;
    s.emplace(-2);
    s.emplace(-1);
    s.emplace(n);
    s.emplace(n+1);
    for (int i = 0; i < n; ++i) {
        auto l = --s.lower_bound(v[i].second), r = s.upper_bound(v[i].second);
        auto ll = ----s.lower_bound(v[i].second), rr = ++s.upper_bound(v[i].second);
        if(*l != -1) {
            ans += (v[i].first)*((*l)-(*ll))*((*r)-v[i].second);
        }
        if(*r != n) {
            ans += (v[i].first)*((*rr)-(*r))*(v[i].second-(*l));
        }
        s.emplace(v[i].second);
    }
    cout << ans << "\n";
    return 0;
}