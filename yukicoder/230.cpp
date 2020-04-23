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
struct LazySegmentTree{
    using T = typename M::T;
    using L = typename M::L;
    int sz, height{};
    vector<T> seg; vector<L> lazy;
    explicit LazySegmentTree(int n) {
        sz = 1; while(sz < n) sz <<= 1, height++;
        seg.assign(2*sz, M::e());
        lazy.assign(2*sz, M::l());
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = M::f(seg[i<<1], seg[(i<<1)|1]);
    }

    T reflect(int k){ return lazy[k] == M::l() ? seg[k] : M::g(seg[k], lazy[k]); }

    void eval(int k){
        if(lazy[k] == M::l()) return;
        lazy[(k<<1)|0] = M::h(lazy[(k<<1)|0], lazy[k]);
        lazy[(k<<1)|1] = M::h(lazy[(k<<1)|1], lazy[k]);
        seg[k] = reflect(k);
        lazy[k] = M::l();
    }
    void thrust(int k){ for (int i = height; i; --i) eval(k>>i); }
    void recalc(int k) { while(k >>= 1) seg[k] = M::f(reflect((k<<1)|0), reflect((k<<1)|1));}
    void update(int a, int b, const L &x){
        thrust(a += sz); thrust(b += sz-1);
        for (int l = a, r = b+1;l < r; l >>=1, r >>= 1) {
            if(l&1) lazy[l] = M::h(lazy[l], x), l++;
            if(r&1) --r, lazy[r] = M::h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    T query(int a, int b){ // [l, r)
        thrust(a += sz);
        thrust(b += sz-1);
        T ll = M::e(), rr = M::e();
        for(int l = a, r = b+1; l < r; l >>=1, r>>=1) {
            if (l & 1) ll = M::f(ll, reflect(l++));
            if (r & 1) rr = M::f(reflect(--r), rr);
        }
        return M::f(ll, rr);
    }
};

struct Monoid{
    using T = array<int, 3>;
    using L = int;
    static T f(T a, T b) {
        return {a[0]+b[0], a[1]+b[1], a[2]+b[2]};
    }
    static T g(T a, L b) {
        if(b == l()) return a;
        else if(b == 1) return {a[2], 0, a[2]};
        else if(b == 2) return {0, a[2], a[2]};
        return e();
    }
    static L h(L a, L b) {
        if(b == l()) return a;
        else return b;
    }
    static T e() { return {0, 0, 0}; }
    static L l() { return 0; }
};
int main() {
    int n, q;
    cin >> n >> q;
    LazySegmentTree<Monoid> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, {0, 0, 1});
    }
    seg.build();
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < q; ++i) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        if(x){
            seg.update(l, r+1, x);
        }else {
            auto res = seg.query(l, r+1);
            if(res[0] < res[1]) ans2 += res[1];
            else if(res[0] > res[1]) ans1 += res[0];
        }
    }
    auto p = seg.query(0, n);
    printf("%lld %lld\n", ans1+p[0], ans2+p[1]);
    return 0;
}