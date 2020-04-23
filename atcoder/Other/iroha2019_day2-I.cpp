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
struct LazySegmentTree{
    using T = typename M::T;
    using L = typename M::L;
    int sz, height{};
    vector<T> seg; vector<L> lazy;
    explicit LazySegmentTree(int n) {
        sz = 1;
        while(sz < n) sz <<= 1, height++;
        seg.assign(2*sz, M::e());
        lazy.assign(2*sz, M::l());
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = M::f(seg[2*i], seg[2*i+1]);
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
        for (int l = a, r = b+1;l < r; l >>= 1, r >>= 1) {
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
    using T = ll;
    using L = ll;
    static T f(T a, T b) { return min(a, b); }
    static T g(T a, L b) {
        return a+b;
    }
    static L h(L a, L b) {
        return a+b;
    }
    static T e() { return INF<ll>; }
    static L l() { return 0; }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int a;
    cin >> a;
    vector<array<int, 3>> Q1(2*a+1);
    for (int i = 0; i < a; ++i) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        Q1[2*i] = {l-1, x, i+1};
        Q1[2*i+1] = {r, -x, i+1};
    }

    Q1.back() = {INF<int>, 0, 0};
    sort(Q1.begin(),Q1.end());
    int b;
    cin >> b;
    vector<array<int, 4>> ar(b);
    for (int i = 0; i < b; ++i) {
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        ar[i] = {k-1, s-1, t+1, i};
    }
    sort(ar.begin(),ar.end());
    LazySegmentTree<Monoid> seg(a+1);
    for (int i = 0; i <= a; ++i) {
        seg.set(i, 0);
    }
    seg.build();
    int cur = 0;
    vector<ll> ans(b);
    for (int i = 0; i < b; ++i) {
        int k = ar[i][0], s = ar[i][1], t = ar[i][2];
        while(Q1[cur][0] <= k){
            seg.update(Q1[cur][2], a+1, Q1[cur][1]);
            cur++;
        }
        ans[ar[i][3]] = v[k] + seg.query(s, t);

    }
    for (auto &&i : ans) {
        printf("%lli\n", i);
    }
    return 0;
}