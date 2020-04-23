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

template <class M>
struct SegmentTree{
    using T = typename M::T;
    int sz;
    vector<T> seg;
    explicit SegmentTree(int n) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2*sz, M::e());
    }

    void set(int k, const T &x){ seg[k + sz] = x; }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = M::f(seg[2*i], seg[2*i+1]);
    }

    void update(int k, const T &x){
        k += sz;
        seg[k] = x;
        while (k >>= 1) seg[k] = M::f(seg[2*k], seg[2*k+1]);
    }

    T query(int a, int b){
        T l = M::e(), r = M::e();
        for(a += sz, b += sz; a < b; a >>=1, b>>=1){
            if(a & 1) l = M::f(l, seg[a++]);
            if(b & 1) r = M::f(seg[--b], r);
        }
        return M::f(l, r);
    }

    template<typename C>
    int find(int t, C &c, T &val, int k, int l, int r){
        if(r-l == 1){
            val = f(val, seg[k]);
            return c(val) ? k-sz : -1;
        }
        int m = (l+r) >> 1;
        if(m <= t) return find(t, c, val, (k << 1) | 1, m, r);
        if(t <= l && !c(val = f(val, seg[k]))) return -1;
        int lv = find(t, c, val, (k << 1) | 0 , l, m);
        if(~lv) return lv;
        return find(t, c, val, (k << 1) | 1, m, r);
    }

    template<typename C>
    int find(int t, C &c){
        T val = M::e();
        return find(t, c, val, 1, 0, sz);
    }
    T operator[](const int &k) const { return seg[k + sz]; }
};


struct Monoid{
    using T = pair<ll, ll>;
    static T f(T a, T b) { return {a.first+b.first, a.second+b.second}; }
    static T e() { return {0, 0}; }
};



int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> ans(q);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    v.emplace_back(-INF<int>, -1);
    sort(v.begin(),v.end(), greater<>());
    vector<array<ll, 4>> query(q);
    int tmp = 0;
    for (int i = 0; i < q; ++i) {
        scanf("%d %lld %lld %lld",&tmp, &query[i][1], &query[i][2], &query[i][0]);
        query[i][3] = i;
    }
    sort(query.begin(),query.end(), greater<>());
    int cur = 0;
    SegmentTree<Monoid> seg(n);
    for (auto &&p : query) {
        while(v[cur].first >= p[0]) {
            seg.update(v[cur].second, {v[cur].first, 1});
            cur++;
        }
        auto res = seg.query(p[1]-1, p[2]);
        ans[p[3]] = res.first-(ll)res.second*p[0];
    }
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}