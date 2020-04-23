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

constexpr int B = 300;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<ll> cnt(n);
    for (auto &&i : v) {
        scanf("%lld", &i);
    }
    auto z(v);
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    for (int i = 0; i < n; ++i) {
        v[i] = lower_bound(z.begin(),z.end(), v[i]) - z.begin();
    }
    using P = array<int, 3>;
    vector<vector<P>> query(n/B+1);
    for (int i = 0; i < q; ++i) {
        P a;
        scanf("%d %d", &a[0], &a[1]);
        a[0]--;
        a[2] = i;
        query[a[0]/B].push_back(a);
    }
    vector<ll> ans(q);
    for (int i = 0; i <= n/B; ++i) {
        sort(query[i].begin(),query[i].end(), [](P a, P b){
            return a[1] < b[1];
        });
        int ub = min((i+1)*B, n);
        int l = 0, r = 0;
        ll val = 0;
        auto add = [&](int p, int x){
            cnt[p] += x;
            val = max(val, cnt[p]*z[p]);
        };
        while(l < ub) add(v[l++], -1);
        for (auto &&a : query[i]) {
            while(r < a[1]) add(v[r++], 1);
            ll tmp = val;
            while(l > a[0]) add(v[--l], 1);
            ans[a[2]] = val;
            while(l < ub) add(v[l++], -1);
            val = tmp;
        }
        fill(cnt.begin(),cnt.end(), 0);
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}