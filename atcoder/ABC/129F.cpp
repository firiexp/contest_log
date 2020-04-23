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

static constexpr int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
constexpr ll E18 = 1000000000000000000;



struct modint {
    static ll &mod(){
        static ll mod_ = 0;
        return mod_;
    }

    static void set_mod(const ll x) { mod() = x; }
    static ll M() {return mod(); }

    ll val;
    modint(): val(0){}
    template<typename T>
    explicit modint(T t){val = t%M(); if(val < 0) val += M();}

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
    modint& operator=(T a){ val = a%M(); if(val < 0) val += M(); return *this; }
    modint inv() {return pow(M()-2);}
    modint& operator+=(modint a){ val += a.val; if(val >= M()) val -= M(); return *this;}
    modint& operator-=(modint a){ val += M()-a.val; if(val >= M()) val -= M(); return *this;}
    modint& operator*=(modint a){ val = val*a.val%M(); return *this;}
    modint& operator/=(modint a){ return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(-val); }
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


int main() {
    ll l, a, b, m;
    cin >> l >> a >> b >> m;
    using mint = modint;
    mint::set_mod(m);
    using mat = SquareMatrix<mint, 3>;
    ll lb = E18/10, ub = E18;
    ll digit = 18;
    mint ans(0);
    mint X(1);
    while(lb){
        if(lb <= a+l*b){
            ll R = l, L = R;
            {
                ll ng = -1;
                while(L-ng > 1){
                    ll mid = (L+ng)/2;
                    if(a+mid*b >= lb) L = mid;
                    else ng = mid;
                }
            }
            mat M;
            M[0][0] = mint(10).pow(digit);
            M[1][0] = 1; M[1][1] = 1; M[2][1] = 1; M[2][2] = 1;
            M = M.pow(R-L);
            mint Y = mint(a+L*b)*M[1][0]+mint(b)*M[2][0];
            ans += X*Y;
            l = L;
            X *= mint(10).pow(R-L).pow(digit);
        }

        lb /= 10; ub /= 10; digit--;
    }
    cout << ans.val << "\n";
    return 0;
}