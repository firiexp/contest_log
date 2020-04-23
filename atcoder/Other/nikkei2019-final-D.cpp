#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class E, class F, class G, class H>
struct lazy_segment_tree{
    int sz, height{};
    vector<T> seg; vector<E> lazy;
    const F f; const G g; const H h;
    const T M; const E L;
    lazy_segment_tree(int n, const F f, const G g, const H h, T M, E L) : f(f), g(g), h(h), M(M) , L(L) {
        sz = 1;
        while(sz < n) sz <<= 1, height++;
        seg.assign(2*sz, M);
        lazy.assign(2*sz, L);
    }

    void set(int k, const T &x){
        seg[k + sz] = x;
    }

    void build(){
        for (int i = sz-1; i > 0; --i) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    T reflect(int k){ return lazy[k] == L ? seg[k] : g(seg[k], lazy[k]); }

    void eval(int k){
        if(lazy[k] == L) return;
        lazy[(k<<1)|0] = h(lazy[(k<<1)|0], lazy[k]);
        lazy[(k<<1)|1] = h(lazy[(k<<1)|1], lazy[k]);
        seg[k] = reflect(k);
        lazy[k] = L;
    }
    void propagate(int k){ for (int i = height; i; --i) eval(k>>i); }
    void recalc(int k) { while(k >>= 1) seg[k] = f(reflect((k<<1)|0), reflect((k<<1)|1));}
    void update(int a, int b, const E &x){ // [l, r)
        propagate(a += sz);
        propagate(b += sz - 1);
        for (int l = a, r = b+1;l < r; l >>=1, r >>= 1) {
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    T query(int a, int b){ // [l, r)
        propagate(a += sz);
        propagate(b += sz - 1);
        T ll = M, rr = M;
        for(int l = a, r = b; l < r; l >>= 1, r>>=1) {
            cout << l << " " << r << "\n";
            if (l & 1) ll = f(ll, reflect(l++));
            if (r & 1) rr = f(reflect(--r), rr);
            cout << l << " " << r << "\n";
        }

        return f(ll, rr);
    }

    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};


int main() {
    int n, q;
    cin >> n >> q;
    auto f=[](ll a,ll b){return a+b;};
    auto g=[](ll a,ll b){return b == 0 ? a : b;};
    auto h=[](ll a,ll b){return b == 0 ? a : b;};
    lazy_segment_tree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, 0, 0);
    for (int i = 0; i < q; ++i) {
        ll t, l, r;
        cin >> t >> l >> r;
        seg.update(l-1, r, t);
    }
    ll s = 7334177222;
    cout << seg.query(0, n) << "\n";
    return 0;
}
