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

    T operator[](const int &k) const { return seg[k + sz]; }
};


struct Monoid{
    using T = int;
    static T f(T a, T b) { return min(a, b); }
    static T e() { return INF<int>; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), t(m);
    vector<int> v(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &s[i], &t[i]);
        v[--s[i]]++;
        if(t[i] != n) v[t[i]]--;
    }
    for (int i = 1; i < n; ++i) {
        v[i] += v[i-1];
    }
    SegmentTree<Monoid> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, v[i]);
    }
    seg.build();
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if(seg.query(s[i], t[i]) >= 2){
            ans.emplace_back(i+1);
        }
    }
    printf("%zu\n", ans.size());
    for (auto &&i : ans) {
        printf("%d\n", i);
    }
    return 0;
}