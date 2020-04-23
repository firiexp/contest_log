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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using namespace __gnu_pbds;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        cnt[x-1]++;
    }
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; ++i) {
        v[cnt[i]].emplace_back(i+1);
    }
    vector<pair<ll, ll>> query(q);
    for (int i = 0; i < q; ++i) {
        ll y;
        scanf("%lld", &y);
        query[i] = {y-n-1, i};
    }
    sort(query.begin(),query.end());
    tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> s;
    vector<ll> ans(q);
    int cur = 0; ll a = 0;
    for (auto &&j : v[0]) {
        s.insert(j);
    }
    for (int i = 0; i < q; ++i) {
        ll val, c; tie(val, c) = query[i];
        while (cur < n && a+s.size() <= val){
            a += s.size();
            cur++;
            for (int j : v[cur]) {
                s.insert(j);
            }
        }
        ans[c] = *s.find_by_order((val-a)%m);
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}