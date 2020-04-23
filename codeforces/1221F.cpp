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
    using T = pair<ll, ll>;
    using L = ll;
    static T f(T a, T b) {
        if(a.first < b.first) return b;
        else return a;
    }
    static T g(T a, L b) {
        return {a.first+b, a.second};
    }
    static L h(L a, L b) {
        return a+b;
    }
    static T e() { return {-1e13, -1}; }
    static L l() { return 0; }
};

int main() {
    int n;
    cin >> n;
    using Arr = array<int, 3>;
    vector<array<int, 3>> v(n);
    vector<int> zs(n);

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[i] = {x, y, z};
        zs[i] = max(x, y);
    }
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    auto f = [&zs](int i){ return lower_bound(zs.begin(),zs.end(), i) - zs.begin(); };

    int m = zs.size();
    LazySegmentTree<Monoid> seg(m+2);
    seg.set(0, {0, 0});
    for (int i = 0; i < m; ++i) {
        seg.set(i+1, {-zs[i], zs[i]});
    }
    seg.build();
    for (int i = 0; i < n; ++i) {
        seg.update(f(max(v[i][0], v[i][1]))+1, m+2, v[i][2]);
    }
    sort(v.begin(),v.end(), [](Arr &a, Arr &b){
        return min(a[0], a[1]) < min(b[0], b[1]);
    });
    ll ans = 0, ansx1 = 0, ansx2 = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i][0] == ansx1 && v[i][1] == ansx2) ansx1++, ansx2++;
    }
    int cur = 0;
    while(cur < n){
        auto a = seg.query(f(min(v[cur][0], v[cur][1]))+1, m+2);
        if(a.first+min(v[cur][0], v[cur][1]) > ans){
            ans = a.first+min(v[cur][0], v[cur][1]);
            ansx1 = min(v[cur][0], v[cur][1]);
            ansx2 = a.second;
        }
        int i = cur;
        while(i < n && min(v[cur][0], v[cur][1]) == min(v[i][0], v[i][1])) {
            seg.update(f(max(v[i][0], v[i][1]))+1, m+2, -v[i][2]);
            i++;
        }
        cur = i;
    }
    cout << ans << "\n";
    cout << ansx1 << " " << ansx1 << " " << ansx2 << " " << ansx2 << "\n";
    return 0;
}