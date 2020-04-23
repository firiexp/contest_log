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

template <class T, class F>
struct segment_tree{
    int sz;
    vector<T> seg;
    const F f;
    const T M;
    segment_tree(int n, const F f, const T &M) : f(f), M(M) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2*sz, M);
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    void update(int k, const T &x){ // 0-indexed
        k += sz;
        seg[k] = x;
        while (k >>= 1){
            seg[k] = f(seg[2*k], seg[2*k+1]);
        }
    }

    T query(int a, int b){ // 0-indexed
        T l = M, r = M;
        for(a += sz, b += sz; a < b; a >>=1, b>>=1){
            if(a & 1) l = f(l, seg[a++]);
            if(b & 1) r = f(seg[--b], r);
        }
        return f(l, r);
    }

    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};

struct tup{
    ll s, p, abs;
    tup (ll s, ll p, ll n) : s(s), p(p), abs(n) {};
};

int main() {
    int n, q;
    cin >> n >> q;
    n *= 2;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    auto f = [](tup a, tup b){
        return tup(a.s+b.s, a.p+b.p, min(a.abs, b.abs));
    };
    segment_tree<tup, decltype(f)> seg(n, f, tup(0, 0, INF<int>));
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        int d = b[i]-a[i];
        seg.set(i,
                tup(max(0, d), d >= 0, abs(d))
                );
    }
    seg.build();
    for (int i = 0; i < q; ++i) {
        int p, x, y;
        scanf("%d %d %d", &p, &x, &y);
        p--;
        s += x - a[p];
        int d = y-x;
        a[p] = x, b[p] = y;
        seg.update(p,
                tup(max(0, d), d >= 0, abs(d))
        );
        auto ret = seg.query(1, n-1);
        ll ans = s + ret.s - ((ret.p)&1 ? ret.abs : 0);
        printf("%lli\n", ans);
    }
    return 0;
}