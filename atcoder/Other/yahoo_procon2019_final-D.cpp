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

template <ll M = MOD> struct modint {
public:
    ll val;
    explicit modint(const ll x = 0) : val(x) {}
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv(){
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n){
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return u;
    }
    modint &operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint &operator-=(const modint a){ val += a.val; if(val < 0) val += M; return *this; }
    modint &operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint &operator/=(const modint a){ val = (val*a.inv()) %M; return *this;}
};

template<class T, size_t SIZE>
struct SquareMatrix {
    using ar = array<T, SIZE>;
    using mat = array<ar, SIZE>;
    mat A;
    SquareMatrix() = default;
    static SquareMatrix I(T e){
        SquareMatrix X;
        for (int i = 0; i < SIZE; ++i) {
            X[i][i] = e;
        }
        return X;
    }

    inline const ar &operator[](int k) const{ return (A.at(k)); }
    inline ar &operator[](int k) { return (A.at(k)); }
    SquareMatrix &operator+= (const SquareMatrix &B){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }

    SquareMatrix &operator-= (const SquareMatrix &B){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }

    SquareMatrix &operator*=(const SquareMatrix &B) {
        SquareMatrix C;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    C[i][j] += ((*this)[i][k] * B[k][j]);
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }

    SquareMatrix pow(ll n) const {
        SquareMatrix a = (*this), res = I(T(1));
        while(n > 0){
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    SquareMatrix operator+(const SquareMatrix &B) const {return SquareMatrix(*this) += B;}
    SquareMatrix operator-(const SquareMatrix &B) const {return SquareMatrix(*this) -= B;}
    SquareMatrix operator*(const SquareMatrix &B) const {return SquareMatrix(*this) *= B;}
};

using Int = modint<MOD>;

using Mat = SquareMatrix<Int, 2>;
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
    using T = SquareMatrix<Int, 2>;
    static T f(T a, T b) { return a*b; }
    static T e() { return T::I(Int(1)); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> query(q);
    vector<int> v;
    v.emplace_back(0);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        if(x == 1){
            int p;
            scanf("%d", &p);
            v.emplace_back(p);
            v.emplace_back(p+1);
            query[i] = vector<int>{p};
        }else {
            int l, r;
            scanf("%d %d", &l, &r);
            v.emplace_back(l);
            v.emplace_back(r+1);
            query[i] = vector<int>{l, r};
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    SegmentTree<Monoid> seg(v.size()-1);
    auto id = [&v](int x){ return lower_bound(v.begin(),v.end(), x)- v.begin(); };
    Mat a, b;
    a[0][0] = a[0][1] = a[1][0] = Int(1); a[1][1] = Int(0);
    b[1][0] = Int(1); b[0][0] = b[0][1] =  b[1][1] = Int(0);
    for (int i = 0; i < v.size()-1; ++i) {
        seg.set(i, a.pow(v[i+1]-v[i]));
    }
    seg.build();
    vector<int> flag(v.size());
    for (int i = 0; i < q; ++i) {
        if(query[i].size() == 1){
            int p = id(query[i].front());
            if(!flag[p]) seg.update(p, b);
            else seg.update(p, a);
            flag[p] ^= 1;
        }else {
            int l = id(query[i].front()), r = id(query[i].back()+1);
            Mat ans = seg.query(l, r);
            cout << ans[0][1].val << "\n";
        }
    }
    return 0;
}