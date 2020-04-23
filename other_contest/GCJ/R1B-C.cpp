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
/*
Use this template
auto f = [](int a, int b){ return min(a, b); }
segment_tree<int, decltype(f)> seg(n, f), INF<int>);
 */

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&i : b) scanf("%d", &i);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int p = 0, q = 0;
            for (int l = i; l <= j; ++l) {
                p = max(p, a[l]);
                q = max(q, b[l]);
            }
            if(abs(p-q) <= k) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
