#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
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

    template<class X>
    int search(int a, int b, X &check, int k, int l, int r){
        if(!check(seg[k]) || r <= a || b <= l) return -1;
        if(k >= sz) return k-sz;
        int lv = search(a, b, check, 2*k, l, (l+r)/2);
        if(lv != -1) return lv;
        return search(a, b, check, 2*k+1, (l+r)/2, r);
    }
    template<class X>
    int search(int a, int b, X &check){
        return search(a, b, check, 1, 0, sz);
    }
    T operator[](const int &k) const { // 0-indexed
        return seg[k + sz];
    }
};
/*
Use this template
auto f = [](int a, int b){ return min(a, b); };
segment_tree<int, decltype(f)> seg(n, f, INF<int>);
 */

int main() {
    int n;
    cin >> n;
    vector<int> c(n), a(n);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &c[i], &a[i]);
    }
    auto f = [](int a, int b){return min(a, b);};
    segment_tree<int, decltype(f)> seg(n, f, -1);
    vector<int> grundy(n);
    grundy[0] = 0;
    seg.update(0, 0);
    for (int i = 1; i < n; ++i) {
        auto check = [&](int x){ return x < i - c[i]; };
        grundy[i] = seg.search(0, n, check);
        seg.update(grundy[i], i);
    }
    int ans = 0;
    for (int j = 1; j < n; ++j) {
        if(a[j] & 1) ans ^= grundy[j];
    }
    puts(ans ? "First" : "Second");
    return 0;
}
