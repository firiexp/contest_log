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

int gcd2(int a, int b){
    if(a == 0 && b == 0) return 0;
    if(a == 0 || b == 0) return a ? a : b;
    return __gcd(abs(a), abs(b));
}


struct MonoidGcd {
    using T = int;
    static T f(T a, T b) { return gcd2(a, b); }
    static T e() { return 0; }
};

template<class T>
class BIT {
    vector<T> bit;
public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    vector<int> u(n+1);
    for (int i = 1; i < n; ++i) u[i] = v[i]-v[i-1];
    u[0] = v[0], u[n] = v.back();
    SegmentTree<MonoidGcd> seg(n+1);
    BIT<int> sum(n+1);
    for (int i = 0; i <= n; ++i) seg.set(i, u[i]), sum.add(i, u[i]);
    seg.build();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if(t == 0){
            cout << gcd2(seg.query(l, r), sum.sum(l-1)) << "\n";
        }else {
            u[l-1] += t; u[r] -= t; seg.update(l-1, u[l-1]), seg.update(r, u[r]);
            sum.add(l-1, t); sum.add(r, -t);
        }
    }
    return 0;
}