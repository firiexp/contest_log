#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cassert>

static const int MOD = 2;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template<class T, T M = 1000000007>
struct modint{
    T v;
    modint(): v(0){}
    explicit modint(int v): v(v) {}
    explicit modint(ll t){v = t%M; if(v < 0) v += M;}

    modint pow(ll k){
        modint res(1), x(v);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    modint& operator=(int a){return (*this) = modint(a);}
    modint inv() {return pow(M-2);}
    modint& operator+=(modint a){ v += a.v; if(v >= M) v -= M; return *this;}
    modint& operator-=(modint a){ v += M-a.v; if(v >= M) v -= M; return *this;}
    modint& operator*=(modint a){ v = 1LL*v*a.v%M; return *this;}
    modint& operator/=(modint a){ return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(v) +=a;}
    modint operator-(modint a) const {return modint(v) -=a;}
    modint operator*(modint a) const {return modint(v) *=a;}
    modint operator/(modint a) const {return modint(v) /=a;}
    modint operator-(){return v ? M-v : v;}
    bool operator==(const modint a) const {return v == a.v;}
    bool operator!=(const modint a) const {return v != a.v;}
    bool operator<(const modint a) const {return v < a.v;}
};

template<class T>
struct matrix {
    vector<vector<T>> A;
    matrix() = default;
    matrix(size_t n, size_t m) : A(n, vector<T>(m)) {}
    explicit matrix(size_t n) : A(n, vector<T> (n)) {};
    size_t height() const { return (A.size()); }
    size_t width() const { return (A[0].size()); }

    const vector<T> &operator [] (int k) const { return A.at(k); }
    vector<T> &operator[] (int k) { return A.at(k); }

    static matrix I(size_t n){
        matrix mat(n);
        for (int i = 0; i < n; ++i) mat[i][i] = -1u;
        return mat;
    }

    matrix &operator+= (const matrix &B){
        size_t h = height(), w = width();
        assert(h == B.height() && w == B.width());
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                (*this)[i][j] += B[i][j];
            }
        }
    }

    matrix &operator-= (const matrix &B){
        size_t h = height(), w = width();
        assert(h == B.height() && w == B.width());
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                (*this)[i][j] -= B[i][j];
            }
        }
    }

    matrix &operator*=(const matrix &B)
    {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        matrix C (n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < p; ++k) {
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }

    template <class U>
    matrix &operator%= (const U &m){
        for (int i = 0; i < height(); ++i) {
            for (int j = 0; j < width(); ++j) {
                (*this)[i][j] %= m;
            }
        }
    }

    matrix pow(ll n) const {
        matrix a = (*this), res = I(height());
        while(n > 0){
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    matrix operator+(const matrix &A) const {return matrix(*this) += A;}
    matrix operator-(const matrix &A) const {return matrix(*this) -= A;}
    matrix operator*(const matrix &A) const {return matrix(*this) *= A;}
    template <class U>
    matrix operator%(const U &m) const {return matrix(*this) %= m;}

};

struct num {
    u32 v;
    num(u32 x) : v(x) {};
    num() : v(0) {};
    num& operator=(u32 x) { this->v = x; return (*this); }
};
num operator+(num a, num b) { return {a.v^b.v}; }
num operator*(num a, num b) { return {a.v&b.v}; }


int main() {
    int n, k;
    cin >> n >> k;
    matrix<num> a(1, n), v(n);
    for (int i = 0; i < n; ++i) {
        u32 x;
        cin >> x;
        a[0][i] = x;
    }
    for (int i = 0; i < n-1; ++i) {
        v[i+1][i] = -1u;
    }
    for (int i = 0; i < n; ++i) {
        u32 x;
        cin >> x;
        v[n-i-1][n-1] = x;
    }
    auto ans = a*(v.pow(k-1));
    cout << ans[0][0].v << "\n";
    return 0;
}
