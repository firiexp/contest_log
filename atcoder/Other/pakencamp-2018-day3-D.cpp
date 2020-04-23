#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
struct segment_tree{
    int sz;
    vector<T> seg;
    const function< T(T, T) > f;
    const T M;
    segment_tree(int n, const function<T(T, T)> f, const T &M) : f(f), M(M) {
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

int main() {
    int n;
    cin >> n;
    vector<ll> v(n-1);
    segment_tree<ll> va(n, [](ll a, ll b){ return (a > b ? a : b); }, -INF<ll>);
    segment_tree<ll> vb(n, [](ll a, ll b){ return (a > b ? a : b); }, -INF<ll>);
    ll s = 0;
    va.set(0, 0);
    for (int i = 0; i < n-1; ++i) {
        int k;
        scanf("%d", &k);
        v[i] = k;
        s += k;
        va.set(i+1, s);
    }
    s = 0;
    vb.set(n-1, 0);
    for (int i = n-2; i >= 0; --i) {
        s += v[i];
        vb.set(i, s);
    }
    va.build();
    vb.build();
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        ll a = va.query(i, n) - va[i];
        ll b = vb.query(0, i+1) - vb[i];
        cout << max(a, b) << "\n";
    }
    return 0;
}
