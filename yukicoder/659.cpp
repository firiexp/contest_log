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
    using T = double;
    static T mul(T x, T y){ return x * y; }
    static void add(T &x, T y){ x += y; }
    static T one(){ return 1.0; }
    static T zero(){ return 0.0; }
};

using ar = array<SemiRing::T, 64>;
using mat = SquareMatrix<SemiRing, 64>;


int main() {
    int r, c, t;
    cin >> r >> c >> t;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    vector<string> v(r);
    for (auto &&i : v) cin >> i;
    array<int, 4> dy = {-1, 1, 0, 0}, dx{0, 0, -1, 1};
    mat A;
    auto f = [&](int y, int x){ return (y-1)*(c-2)+x-1; };
    for (int i = 1; i < r-1; ++i) {
        for (int j = 1; j < c-1; ++j) {
            if(v[i][j] == '#') continue;

            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                if(v[i+dy[k]][j+dx[k]] == '.') cnt++;
            }
            if(!cnt){
                A[f(i, j)][f(i, j)] = 1;
            }else {
                for (int k = 0; k < 4; ++k) {
                    if(v[i+dy[k]][j+dx[k]] == '.'){
                        A[f(i, j)][f(i+dy[k], j+dx[k])] = 1.0/cnt;
                    }
                }
            }
        }
    }
    A = A.pow(t);
    printf("%.10lf\n", A[f(sy, sx)][f(gy, gx)]);
    return 0;
}