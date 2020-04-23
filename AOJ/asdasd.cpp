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
    void thrust(int k){ for (int i = height; i; --i) eval(k>>i); }
    void recalc(int k) { while(k >>= 1) seg[k] = f(reflect((k<<1)|0), reflect((k<<1)|1));}
    void update(int a, int b, const E &x){ // [l, r)
        thrust(a += sz); thrust(b += sz-1);
        for (int l = a, r = b+1;l < r; l >>=1, r >>= 1) {
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    T query(int a, int b){ // [l, r)
        thrust(a += sz);
        thrust(b += sz-1);
        T ll = M, rr = M;
        for(int l = a, r = b+1; l < r; l >>=1, r>>=1) {
            if (l & 1) ll = f(ll, reflect(l++));
            if (r & 1) rr = f(reflect(--r), rr);
        }
        return f(ll, rr);
    }

    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};
/*
Use this template
using P = pair<ll, ll>;
auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
auto h=[](ll a,ll b){return a+b;};
lazy_segment_tree<P, ll, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, P(0, 0), 0LL);
for (int i = 0; i < n; ++i) {
    seg.set(i, P(0, 1));
}
seg.build();

auto f=[](ll a,ll b){return a+b;};
auto g=[](ll a,ll b){return max(a,b) ;};
auto h=[](ll a,ll b){return max(a,b) ;};
lazy_segment_tree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, 0, 0);

 */

int main() {
    int n, q;
    cin >> n >> q;
    auto f=[](int a,int b){return min(a, b);};
    auto g=[](int a,int b){return b == 1 << 31? a : b; };
    auto h=[](int a,int b){return b ==  ? a : b; };
    lazy_segment_tree<int, int, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, INF<int>, INF<int>);
    for (int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        if(c == 0){
            int s, t, x;
            cin >> s >> t >> x;
            seg.update(s-1, t, x);
        }else {
            int  s, t;
            cin >> s >> t;
            cout << seg.query(s-1, t) << "\n";
        }
    }
    cout << seg.query(0, n) << "\n";
    return 0;
}
