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

struct Query {
    int val, no;
    Query(int val, int no) : val(val), no(no) {}
    Query() : val(0), no(0) {}
    bool operator<(const Query &a) const {
        return this->val < a.val;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v(n);
    ll val = 0, val2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        val += (ll)v[i].first*v[i].second;
        val2 -= v[i].second;
    }
    sort(v.begin(),v.end());
    int cur = 0;
    vector<Query> Q(q);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        Q[i] = {x, i};
    }
    sort(Q.begin(),Q.end());
    vector<ll> ans(q);
    for (int i = 0; i < q; ++i) {
        while(cur < n && v[cur].first < Q[i].val){
            val -= 2LL*v[cur].first*v[cur].second;
            val2 += 2*v[cur].second;
            cur++;
        }
        ans[Q[i].no] = val2*Q[i].val+val;
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}