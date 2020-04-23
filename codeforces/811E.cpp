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

class UnionFind {
    int n;
public:
    vector<int> uni;
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1){};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};
int n, m, q;

UnionFind uf(40);

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
    using T = array<int, 41>;
    static T f(T a, T b) {
        if(a == e()) return b;
        else if(b == e()) return a;

        T res;
        for (int i = 0; i < n; ++i) res[i] = a[i], res[i+10] = b[i+10];
        res[40] = a[40]+b[40];
        fill(uf.uni.begin(),uf.uni.end(), -1);
        for (int i = 0; i < 20; ++i) {
            for (int j = i+1; j < 20; ++j) {
                if(a[20+i] == a[20+j]) uf.unite(i, j);
                if(b[20+i] == b[20+j]) uf.unite(i+20, j+20);
            }
        }
        for (int i = 0; i < n; ++i) {
            if(a[i+10] == b[i]) res[40] -= uf.unite(i+10, i+20);
        }
        for (int i = 0; i < n; ++i) {
            res[20+i] = uf.root(i);
            res[30+i] = uf.root(30+i);
        }
        return res;
    }
    static T e() { return {}; }
};

int main() {
    cin >> n >> m >> q;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    SegmentTree<Monoid> seg(m);
    for (int i = 0; i < m; ++i) {
        Monoid::T x;
        x[40] = n;
        for (int j = 0; j < n; ++j) {
            x[j] = v[j][i];
            x[10+j] = v[j][i];
        }
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if(j) {
                if(v[j-1][i] == v[j][i]) x[40]--;
                else cur++;
            }
            x[20+j] = x[30+j] = cur;
        }
        seg.set(i, x);
    }
    seg.build();
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", seg.query(a-1, b)[40]);
    }
    return 0;
}