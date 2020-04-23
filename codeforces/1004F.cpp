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

struct Data{
    ll ans;
    vector<pair<int, int>> l, r;
    Data() : ans(0), l(0), r(0) {};
    Data(ll ans, vector<pair<int, int>> &l, vector<pair<int, int>> &r) : ans(ans), l(l), r(r) {}
};

int X;
struct Monoid{
    using T = Data;
    static T f(T a, T b) {
        if(a.l.empty()) return b;
        else if(b.l.empty()) return a;
        ll ans = a.ans + b.ans, val = 0;
        int cur = (int)b.l.size()-1;
        for (int i = 0; i < a.r.size(); ++i) {
            while(cur >= 0 && (a.r[i].first|b.l[cur].first) >= X){
                val += b.l[cur].second;
                cur--;
            }
            ans += val*a.r[i].second;
        }
        for (auto &&i : b.l) {
            if((a.l.back().first|i.first) == a.l.back().first) {
                a.l.back().second += i.second;
            }else {
                a.l.emplace_back(i.first|a.l.back().first, i.second);
            }
        }
        for (auto &&i : a.r) {
            if((b.r.back().first|i.first) == b.r.back().first){
                b.r.back().second += i.second;
            }else {
                b.r.emplace_back(i.first|b.r.back().first, i.second);
            }
        }
        return {ans, a.l, b.r};
    }
    static T e() { return Data(); }
};

int main() {
    int n, m;
    cin >> n >> m >> X;
    SegmentTree<Monoid> seg(n);
    vector<pair<int, int>> v(1);
    v[0].second = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[0].first);
        seg.set(i, Data(v[0].first >= X, v, v));
    }
    seg.build();
    for (int i = 0; i < m; ++i) {
        int t; scanf("%d", &t);
        if(t == 1){
            int a; scanf("%d %d", &a, &v[0].first);
            seg.update(a-1, Data(v[0].first >= X, v, v));
        }else {
            int l, r; scanf("%d %d", &l, &r);
            printf("%lld\n", seg.query(l-1, r).ans);
        }
    }
    return 0;
}