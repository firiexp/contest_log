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

template<class T, T M = 1000000007>
struct modint{
    T val;
    modint(): val(0){}
    explicit modint(int v): val(v) {}
    explicit modint(ll t){val = t%M; if(val < 0) val += M;}

    modint pow(ll k){
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    modint& operator=(int a){return (*this) = modint(a);}
    modint inv() {return pow(M-2);}
    modint& operator+=(modint a){ val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){ val += M-a.val; if(val >= M) val -= M; return *this;}
    modint& operator*=(modint a){ val = 1LL*val*a.val%M; return *this;}
    modint& operator/=(modint a){ return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return val ? M-val : val;}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
#include <assert.h>
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
        for (int i = 0; i < n; ++i) mat[i][i] = 1;
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



int main() {
    int n;
    cin >> n;
    matrix<modint<int>> v(3);
    v[0][1] = 1, v[1][0] = 1, v[1][2] = 1, v[2][0] = 1;
    auto v2 = v.pow(n-1);
    cout << (v2[0][0] + v2[1][0] + v2[2][0]).val << "\n";
    return 0;
}
