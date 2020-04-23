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
using u32 = unsigned;
using u64 = unsigned long long;

using namespace std;
using namespace __gnu_pbds;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ans1(n), ans2(n), v(m);
    iota(ans1.begin(),ans1.end(), 1);
    iota(ans2.begin(),ans2.end(), 1);

    for (auto &&i : v) scanf("%d", &i), i--, ans1[i] = 1;
    tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> s;
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        s.insert(make_pair(i+1, i));
        val[i] = i+1;
    }

    for (int i = 0; i < m; ++i) {
        ans2[v[i]] = max<int>(ans2[v[i]],
                s.order_of_key(make_pair(val[v[i]], v[i]))+1
        );
        s.erase(make_pair(val[v[i]], v[i]));
        val[v[i]] = -i;
        s.insert(make_pair(val[v[i]], v[i]));
    }
    for (int i = 0; i < n; ++i) {
        ans2[i] = max<int>(ans2[i],
                s.order_of_key(make_pair(val[i], i))+1
        );
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans1[i], ans2[i]);
    }
    return 0;
}