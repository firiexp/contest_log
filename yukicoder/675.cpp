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

template<class H, size_t SIZE>
struct SquareMatrix {
    using T = typename H::T;
    using ar = array<T, SIZE>;
    using mat = array<ar, SIZE>;
    mat A;
    SquareMatrix() = default;
    static SquareMatrix I(){
        SquareMatrix X{};
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if(i == j) X[i][j] = H::one();
                else X[i][j] = H::zero();
            }
        }
        return X;
    }

    friend ar operator*=(ar &x, const SquareMatrix &Y) {
        ar ans{};
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                 H::add(ans[j], H::mul(x[i], Y[i][j]));
            }
        }
        x.swap(ans);
        return x;
    }
    friend ar operator*(ar x, const SquareMatrix &Y) { return x *= Y; }

    inline const ar &operator[](int k) const{ return (A.at(k)); }
    inline ar &operator[](int k) { return (A.at(k)); }
    SquareMatrix &operator+= (const SquareMatrix &B){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                H::add((*this)[i][j], B[i][j]);
            }
        }
        return (*this);
    }

    SquareMatrix &operator-= (const SquareMatrix &B){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                H::add((*this)[i][j], -B[i][j]);
            }
        }
        return (*this);
    }

    SquareMatrix &operator*=(const SquareMatrix &B) {
        SquareMatrix C{};
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    H::add(C[i][j],  H::mul((*this)[i][k], B[k][j]));
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }

    SquareMatrix pow(ll n) const {
        SquareMatrix a = (*this), res = I();
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

struct SemiRing {
    using T = int;
    static T mul(T x, T y){ return x * y; }
    static void add(T &x, T y){ x += y; }
    static T one(){ return 1.0; }
    static T zero(){ return 0.0; }
};

using ar = array<SemiRing::T, 3>;
using mat = SquareMatrix<SemiRing, 3>;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<mat> v(n, mat::I());
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if(k == 1){
            int d;
            scanf("%d", &d);
            v[i][2][0] = d;
        }else if(k == 2){
            int d;
            scanf("%d", &d);
            v[i][2][1] = d;
        }else {
            v[i][0][0] = 0; v[i][1][0] = 1;
            v[i][0][1] = -1, v[i][1][1] = 0;
        }
    }
    for (int i = n-2; i >= 0; --i) {
        v[i] *= v[i+1];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", x*v[i][0][0]+y*v[i][1][0]+v[i][2][0],
                               x*v[i][0][1]+y*v[i][1][1]+v[i][2][1]);
    }
    return 0;
}