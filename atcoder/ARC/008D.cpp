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
    using T = pair<double, double>;
    static T f(T a, T b) { return {a.first*b.first, a.second*b.first+b.second}; }
    static T e() { return {1, 0}; }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<double, double>>> query(m);
    vector<ll> atsu(m);
    for (int i = 0; i < m; ++i) {
        ll p; double a, b;
        scanf("%lld %lg %lg", &p, &a, &b);
        query[i] = {p, {a, b}};
        atsu[i] = p;
    }
    sort(atsu.begin(), atsu.end());
    atsu.erase(unique(atsu.begin(), atsu.end()), atsu.end());
    auto z = [&atsu](ll x){ return lower_bound(atsu.begin(),atsu.end(), x) - atsu.begin(); };
    double ans1 = 1, ans2 = 1;
    SegmentTree<Monoid> seg(atsu.size());
    for (int i = 0; i < m; ++i) {
        seg.update(z(query[i].first), query[i].second);
        auto ret = seg.query(0, atsu.size());
        auto a = ret.first+ret.second;
        ans1 = min(ans1, a);
        ans2 = max(ans2, a);
    }
    printf("%.10g\n%.10g\n", ans1, ans2);
    return 0;
}