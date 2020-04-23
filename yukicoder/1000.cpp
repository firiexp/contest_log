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
    using T = pair<ll, ll>;
    using L = ll;
    static T f(T a, T b) { return {a.first+b.first, a.second+b.second}; }
    static T g(T a, L b) {
        return {a.first+a.second*b, a.second};
    }
    static L h(L a, L b) {
        return a+b;
    }
    static T e() { return {0, 0}; }
    static L l() { return 0; }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> imos(n+1);
    vector<ll> ans(n);
    vector<char> cs(q);
    vector<int> xs(q), ys(q);
    LazySegmentTree<Monoid> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, {0, 1});
    }
    seg.build();
    for (int i = 0; i < q; ++i) {
        char c; int x, y;
        scanf(" %c %d %d", &c, &x, &y);
        cs[i] = c; xs[i] = x; ys[i] = y;
        if(c == 'B'){
            imos[x-1]++; imos[y]--;
            seg.update(x-1, y, 1);
        }
    }
    for (int i = 0; i < q; ++i) {
        if(cs[i] == 'A'){
            ans[xs[i]-1] += ys[i]*seg.query(xs[i]-1, xs[i]).first;
        } else seg.update(xs[i]-1, ys[i], -1);
    }
    for (int i = 0; i < n; ++i) {
        imos[i+1] += imos[i];
    }

    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", ans[i]+(ll)v[i]*imos[i]);
    }

    return 0;
}