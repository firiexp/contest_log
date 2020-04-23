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
    static T f(T a, T b) { return {max(b.first, a.first+b.second), a.second+b.second}; }
    static T e() { return {0, 0}; }
};

int main() {
    int q; ll k;
    cin >> q >> k;
    vector<array<int, 3>> Q(q);
    vector<int> z(q);
    z.emplace_back(0);
    for (int i = 0; i < q; ++i) {
        int t; scanf("%d", &t);
        if(t == 1){
            int a, b; scanf("%d %d", &a, &b);
            Q[i] = {t, a, b};
            z[i] = a;
        }else {
            int x; scanf("%d", &x);
            Q[i] = {t, x, 0};
            z[i] = x;
        }
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    SegmentTree<Monoid> seg(z.size()-1);
    vector<ll> val(z.size()-1);
    for (int i = 0; i+1 < z.size(); ++i) {
        seg.set(i,  {0, k*(z[i+1]-z[i])});
        val[i] = k*(z[i+1]-z[i]);
    }
    seg.build();
    for (int i = 0; i < q; ++i) {
        int d = lower_bound(z.begin(),z.end(), Q[i][1]) - z.begin()-1;
        if(Q[i][0] == 1){
            val[d] -= Q[i][2];
            seg.update(d, {0, val[d]});
        }else {
            auto ret = seg.query(0, d+1);
            printf("%lld\n", k*z[d+1]-max(ret.first, ret.second));
        }
    }
    return 0;
}