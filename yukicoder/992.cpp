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
    using T = pair<int, int>;
    static T f(T a, T b) {
        if(a.first != b.first) return max(a, b);
        else return {a.first, (a.second+b.second)%MOD};
    }
    static T e() { return {-1, 0}; }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto z = v;
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    for (int i = 0; i < n; ++i) {
        v[i] = lower_bound(z.begin(),z.end(), v[i]) - z.begin();
    }
    SegmentTree<Monoid> seg(z.size());
    for (int i = 0; i < n; ++i) {
        auto ret = seg.query(0, v[i]);
        ret.first++;
        if(ret.first == 0) ret.first++, ret.second = 1;
        auto x = seg.query(v[i], v[i]+1);
        seg.update(v[i], Monoid::f(ret, x));
    }
    cout << seg.query(0, z.size()).second << "\n";
    return 0;
}