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

template <ll M = MOD> struct modint {
    ll val;
    modint(const ll x = 0) : val(x) {
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
    }

    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv() const {
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n) const {
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return modint(u);
    }
    modint& operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint& operator-=(const modint a){ val -= a.val; if(val < 0) val += M; return *this; }
    modint& operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint& operator/=(const modint a){ val = val * a.inv().val % M; return *this;}

    modint& operator=(const int& x){
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
        return *this;
    }
};

using mint = modint<MOD>;
using mat = SquareMatrix<mint, 2>;
int main() {
    ll b, c, d;
    cin >> b >> c >> d;
    mat A;
    A[0][0] = mint(c); A[1][0] = 1; A[1][1] = 1;
    A = A.pow(d);
    cout << ((A[0][0] + A[1][0]-mint(1))*mint(b)).val << "\n";
    return 0;
}