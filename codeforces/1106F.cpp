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
#include <unordered_map>
static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<u32 M = MOD>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;
using mintp = modint<MOD-1>;

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
            for (int k = 0; k < SIZE; ++k) {
                for (int j = 0; j < SIZE; ++j) {
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
    using T = mintp;
    static inline T mul(T x, T y){ return x * y; }
    static inline void add(T &x, T y){ x += y; }
    static inline T one(){ return {1}; }
    static inline T zero(){ return {0}; }
};

using ar = array<SemiRing::T, 100>;
using mat = SquareMatrix<SemiRing, 100>;

int modlog(int g, int y, int m){ // g^x = y (mod m)
    if(y == 1) return 0;
    if(g == 0 && y == 0) return 1;
    int B = sqrt(m)+100;
    unordered_map<int, int> table;
    ll val = 1;
    for (int i = 0; i < B; ++i) {
        if(val == y) return i;
        table[val*y%m] = i;
        val = val*g%m;
    }
    ll val2 = 1;
    for (int i = 1; i <= B; ++i) {
        val2 = val2*val%m;
        auto x = table.find(val2);
        if(x != table.end()){
            return i*B - x->second;
        }
    }
    return -1;
}

int solve(int a, int b, int m){ // a*x = b (mod m)
    int B = sqrt(m)+100;
    unordered_map<int, int> table;
    ll val = 0;
    for (int i = 0; i < B; ++i) {
        if(val == b) return i;
        table[(b+val)%m] = i;
        val = (val + a) % m;
    }
    ll val2 = 0;
    for (int i = 1; i <= B; ++i) {
        val2 = (val2+val)%m;
        auto x = table.find(val2);
        if(x != table.end()){
            return i*B - x->second;
        }
    }
    return -1;
}


int main() {
    int k;
    cin >> k;
    mat X;
    for (int i = 0; i < k-1; ++i) {
        X[i][i+1] = 1;
    }
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        X[k-1][k-1-i] = x;
    }
    int n, m;
    cin >> n >> m;
    ar A;
    A[0] = 1;
    A *= X.pow(n-1);
    ll x = modlog(3, m, MOD); // 3^x = m (mod 998244353)
    int ans = solve(A[k-1].val, x, MOD-1);
    if(ans == -1){
        puts("-1");
    }else {
        cout << mint(3).pow(ans).val << "\n";
    }
    return 0;
}