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

template<ll M = 1000000007>
struct modint{
    ll val;
    modint(): val(0){}
    template<typename T>
    explicit modint(T t){val = t%M; if(val < 0) val += M;}

    modint pow(ll k){
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T a){ val = a%M; if(val < 0) val += M; return *this; }
    modint inv() {return pow(M-2);}
    modint& operator+=(modint a){ val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){ val += M-a.val; if(val >= M) val -= M; return *this;}
    modint& operator*=(modint a){ val = 1LL*val*a.val%M; return *this;}
    modint& operator/=(modint a){ return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){ return modint(-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
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
using mint = modint<>;
using mint2 = modint<MOD-1>;
using Mat = SquareMatrix<mint2, 3>;

using Mat2 = SquareMatrix<mint2, 5>;

int main() {
    ll n, a, b, w, d;
    cin >> n >> a >> b >> w >> d;
    mint f1(a), f2(b), f3(w), c(d);
    Mat A;
    A[0][2] = 1; A[1][0] = 1; A[1][2] = 1; A[2][1] = 1; A[2][2] = 1;
    A = A.pow(n-1);
    mint ans(1);
    ans *= f1.pow(A[0][0].val);
    ans *= f2.pow(A[1][0].val);
    ans *= f3.pow(A[2][0].val);
    Mat2 X;
    X[1][0] = 1; X[0][2] = 1; X[1][2] = 1; X[2][1] = 1; X[2][2] = 1; X[3][2] = 1;
    X[3][3] = 1; X[4][3] = 1; X[4][4] = 1;
    X = X.pow(n-3);
    mint ans2 = c.pow(X[3][2].val*2+X[4][2].val*2);
    cout << (ans*ans2).val << "\n";
    return 0;
}