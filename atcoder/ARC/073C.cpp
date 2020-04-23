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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

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
auto f = [](int a, int b){ return min(a, b); };
segment_tree<int, decltype(f)> seg(n, f, INF<int>);
 */

int main() {
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<P> u(n);
    int mi2 = INF<int>, Ma1 = 0;
    int mi1 = INF<int>, Ma2 = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        chmin(mi2, a); chmin(mi2, b);
        chmax(Ma1, a); chmax(Ma1, b);
        chmin(mi1, max(a, b)); chmax(Ma2, min(a, b));
        u[i] = make_pair(min(a, b), max(a, b));
    }
    ll ans = (ll)(Ma2-mi2)*(Ma1-mi1);
    sort(u.begin(), u.end());
    auto f = [](int a, int b){ return min(a, b); };
    segment_tree<int, decltype(f)> seg1(n, f, INF<int>);
    auto g = [](int a, int b){ return max(a, b); };
    segment_tree<int, decltype(g)> seg2(n, g, 0);
    for (int i = 0; i < n; ++i) {
        seg1.set(i, u[i].first);
        seg2.set(i, u[i].first);
    }
    seg1.build(); seg2.build();
    int ans2 = INF<int>;
    chmin(ans2, seg2.query(0, n)-seg1.query(0, n));
    for (int i = 0; i < n; ++i) {
        seg1.update(i, u[i].second);
        seg2.update(i, u[i].second);
        chmin(ans2, seg2.query(0, n)-seg1.query(0, n));
    }
    cout << min(ans, (ll)ans2*(Ma1-mi2)) << "\n";
    return 0;
}
