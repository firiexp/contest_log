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
        for(a += sz, b += sz; a < b; a >>=1 , b>>=1){
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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


struct Monoid{
    using T = pair<ll, ll>; // 区間の総和, 最大値
    static T f(T a, T b) {
        return {a.first + b.first, max(a.second, b.second+a.first) };
    }
    static T e() {
        return {0, 0};
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> v(n-1);
    SegmentTree<Monoid> seg(n-1);
    for (int i = 0; i < n-1; ++i) {
        scanf("%lld", &v[i]);
        v[i] += (n-i-1)*3;
    }
    for (int i = n-2; i >= 0; --i) {
        if(i) v[i] -= v[i-1];
        seg.set(i, {v[i], v[i]});
    }
    seg.build();
    int q;
    cin >> q;
    while(q--){
        int l, r, val;
        scanf("%d %d %d", &l, &r, &val);
        l--;
        v[l] += val;
        seg.update(l, {v[l], v[l]});
        if(r != n-1){
            v[r] -= val;
            seg.update(r, {v[r] , v[r]});
        }
        printf("%lld\n", seg.query(0, n-1).second);
    }
    return 0;
}