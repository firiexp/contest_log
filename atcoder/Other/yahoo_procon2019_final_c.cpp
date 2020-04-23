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

    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};

struct Monoid{
    using T = array<int, 4>;
    using L = pair<int, int>;
    static T f(T a, T b) {
        return {a[0]+b[0], a[1]+b[1], a[2]+b[2], a[3]+b[3]};
    }
    static T g(T a, L b) {
        if(b.first) swap(a[0], a[1]);
        if(b.second) swap(a[2], a[3]);
        return a;
    }
    static L h(L a, L b) {
        return {a.first^b.first, a.second^b.second};
    }
    static T e() { return {0, 0, 0, 0}; }
    static L l() { return {0, 0}; }
};



int main() {
    int n;
    cin >> n;
    vector<array<int, 4>> Q(2*n+1);
    vector<int> z(2*n+2);
    z.front() = 0; z.back() = 1000000005;
    auto z2 = z;
    for (int i = 0; i < n; ++i) {
        int h, w, r, c;
        scanf("%d %d %d %d", &h, &w, &r, &c);
        z[2*i+1] = r, z[2*i+2] = r+h;
        z2[2*i+1] = c, z2[2*i+2] = c+w;
        Q[2*i] = {r, r, c, c+w};
        Q[2*i+1] = {r+h, r, c, c+w};
    }
    Q.back() = {INF<int>};
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    sort(z2.begin(), z2.end());
    z2.erase(unique(z2.begin(), z2.end()), z2.end());
    auto g = [&z2](int x){ return lower_bound(z2.begin(),z2.end(), x) - z2.begin(); };
    sort(Q.begin(),Q.end());
    int m = (int)z2.size()-1;
    LazySegmentTree<Monoid> seg1(m), seg2(m);
    for (int i = 0; i < m; ++i) {
        int l = z2[i], r = z2[i+1];
        seg1.set(i, {0, (r+1)/2-(l+1)/2, 0, r/2-l/2});
        seg2.set(i, {0, (r+1)/2-(l+1)/2, 0, r/2-l/2});
    }
    seg1.build();
    seg2.build();
    ll ans = 0;
    int cur = 0;
    for (int i = 1; i+2 < z.size(); ++i) {
        while(Q[cur][0] <= z[i]){
            seg1.update(g(Q[cur][2]), g(Q[cur][3]), (Q[cur][1]+Q[cur][2])&1 ? make_pair(1, 0) : make_pair(0, 1));
            seg2.update(g(Q[cur][2]), g(Q[cur][3]), (Q[cur][1]+Q[cur][2])&1 ? make_pair(0, 1) : make_pair(1, 0));
            cur++;
        }
        auto ret1 = seg1.query(0, m);
        auto ret2 = seg2.query(0, m);
        ll l = z[i], r = z[i+1];
        ll a = r/2-l/2, b = (r+1)/2-(l+1)/2;
        ans += a*(ret1[0]+ret1[2])+b*(ret2[0]+ret2[2]);
    }
    cout << ans << "\n";
    return 0;
}