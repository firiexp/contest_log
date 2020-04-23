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
struct DualSegmentTree{
    using T = typename M::T;
    int sz, height{};
    vector<T> lazy;
    explicit DualSegmentTree(int n) {
        sz = 1; while(sz < n) sz <<= 1, height++;
        lazy.assign(2*sz, M::e());
    }

    void eval(int k){
        if(lazy[k] == M::e()) return;
        lazy[(k<<1)|0] = M::f(lazy[(k<<1)|0], lazy[k]);
        lazy[(k<<1)|1] = M::f(lazy[(k<<1)|1], lazy[k]);
        lazy[k] = M::e();
    }
    void thrust(int k){ for (int i = height; i; --i) eval(k>>i); }
    void update(int a, int b, const T &x){
        thrust(a += sz); thrust(b += sz-1);
        for (int l = a, r = b+1;l < r; l >>=1, r >>= 1) {
            if(l&1) lazy[l] = M::f(lazy[l], x), l++;
            if(r&1) --r, lazy[r] = M::f(lazy[r], x);
        }
    }

    T operator[](int k){
        thrust(k += sz);
        return lazy[k];
    }
};

struct Monoid{
    using T = ll;
    static T f(T a, T b) { return a+b; }
    static T e() { return 0; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ok = 100001, ng = 0;
    DualSegmentTree<Monoid> seg1(n), seg2(n); // seg1 : 傾き, seg2: 定数項
    vector<int> xs(m), ws(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &xs[i], &ws[i]);
        xs[i]--;
    }
    if(accumulate(ws.begin(),ws.end(), 0LL) < *min_element(v.begin(),v.end())) {
        puts("0");
        return 0;
    }
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        fill(seg1.lazy.begin(),seg1.lazy.end(), 0);
        fill(seg2.lazy.begin(),seg2.lazy.end(), 0);
        for (int i = 0; i < m; ++i) {
            if(xs[i] != 0 && ws[i]/mid != 0) {
                ll l = max(0, xs[i]-ws[i]/mid), r = xs[i];
                seg1.update(l, r, mid);
                seg2.update(l, r, ws[i]-mid*r);
            }
            ll l = xs[i], r = min(n, xs[i]+ws[i]/mid+1);
            seg1.update(l, r, -mid);
            seg2.update(l, r, ws[i]+mid*l);
        }
        int good = 1;
        for (int j = 0; j < n; ++j) {
            if(seg1[j] * j + seg2[j] >= v[j]){
                good = 0;
                break;
            }
        }
        if(good) ok = mid;
        else ng = mid;
    }
    if(ok == 100001){
        puts("-1");
    }else {
        cout << ok << "\n";
    }
    return 0;
}