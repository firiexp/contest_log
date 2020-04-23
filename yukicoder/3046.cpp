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

#include <cmath>
namespace FFT {
    const int max_base = 18, maxN = 1 << max_base; // N <= 2e5
    const double PI = acos(-1);
    struct num {
        double x{}, y{};
        num() = default;
        num(double x, double y): x(x), y(y) {}
        explicit num(double r): x(cos(r)), y(sin(r)) {}
    };
    num operator+(num a, num b) { return {a.x + b.x, a.y + b.y}; }
    num operator-(num a, num b) { return {a.x - b.x, a.y - b.y}; }
    num operator*(num a, num b) { return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
    num conj(num a) {return {a.x, -a.y}; }
    num root[maxN];
    int rev[maxN];
    bool is_root_prepared = false;

    void prepare_root(){
        if(is_root_prepared) return;
        is_root_prepared = true;
        root[1] = num(1, 0);
        for (int i = 1; i < max_base; ++i) {
            num x(2*PI / (1LL << (i+1)));
            for (ll j = (1LL << (i-1)); j < (1LL << (i)); ++j) {
                root[2*j] = root[j];
                root[2*j+1] = root[j]*x;
            }
        }
    }

    int base, N;
    int lastN = -1;

    void prepare_rev(){
        if(lastN == N) return;
        lastN = N;
        for (int i = 0; i < N; ++i) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }

    void fft(num *a, num *f){
        for (int i = 0; i < N; ++i) f[i] = a[rev[i]];
        for (int k = 1; k < N; k <<= 1) {
            for (int i = 0; i < N; i += 2*k) {
                for (int j = 0; j < k; ++j) {
                    num z = f[i+j+k]* root[j+k];
                    f[i+j+k] = f[i+j] - z;
                    f[i+j] = f[i+j] + z;
                }
            }
        }
    }
    num a[maxN], b[maxN], f[maxN], g[maxN];
    ll A[maxN], B[maxN], C[maxN];

    void multi_mod(int m){
        for (int i = 0; i < N; ++i) {
            ll x = A[i] % m;
            a[i] = num(x & ((1LL << 15)-1), x >> 15);
        }
        for (int i = 0; i < N; ++i) {
            ll x = B[i] % m;
            b[i] = num(x & ((1LL << 15)-1), x >> 15);
        }
        fft(a, f);
        fft(b, g);
        for (int i = 0; i < N; ++i) {
            int j = (N-i) &(N-1);
            num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
            num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
            num b1 = (g[i] + conj(g[j])) * num(0.5/N, 0);
            num b2 = (g[i] - conj(g[j])) * num(0, -0.5/N);
            a[j] = a1*b1 + a2*b2 * num(0, 1);
            b[j] = a1*b2 + a2*b1;
        }
        fft(a, f);
        fft(b, g);
        for (int i = 0; i < N; ++i) {
            ll aa = f[i].x + 0.5;
            ll bb = g[i].x + 0.5;
            ll cc = f[i].y + 0.5;
            C[i] = (aa + bb % m * (1LL << 15) + cc% m *(1LL << 30)) % m;
        }
    }

    void prepare_AB(int n1, int n2){
        base = 1;
        N = 2;
        while(N < n1+n2) base++, N <<= 1;
        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;
        prepare_root();
        prepare_rev();
    }

    void multi_mod(int n1, int n2, int m){
        prepare_AB(n1, n2);
        multi_mod(m);
    }
}

struct poly {
    vector<int> v;
    poly() = default;
    explicit poly(vector<int> vv) : v(std::move(vv)) {};
    int size() {return (int)v.size(); }
    poly cut(int len){
        if(len < v.size()) v.resize(static_cast<unsigned long>(len));
        return *this;
    }
    inline int& operator[] (int i) {return v[i]; }
};

poly operator+(poly &A, poly &B){
    poly C;
    C.v = vector<int>(max(A.size(), B.size()));
    for (int i = 0; i < A.size(); ++i) C[i] = A[i];
    for (int i = 0; i < B.size(); ++i) (C[i] += B[i]) %= MOD;
    return C;
}

poly operator-(poly &A, poly &B){
    poly C;
    C.v = vector<int>(max(A.size(), B.size()));
    for (int i = 0; i < A.size(); ++i) C[i] = A[i];
    for (int i = 0; i < B.size(); ++i) (C[i] += MOD-B[i]) %= MOD;
    return C;
}

poly operator* (poly &A, poly &B){
    poly C;
    C.v = vector<int>(A.size() + B.size()-1);
    for (int i = 0; i < A.size(); ++i) FFT::A[i] = A[i];
    for (int i = 0; i < B.size(); ++i) FFT::B[i] = B[i];
    FFT::multi_mod(A.size(), B.size(), MOD);
    for (int i = 0; i < C.size(); ++i) C[i] = FFT::C[i];
    return C;
}

template<typename T>
T extgcd(T a, T b, T &x ,T &y){
    for (T u = y = 1, v = x = 0; a; ) {
        ll q = b/a;
        swap(x -= q*u, u);
        swap(y -= q*v, v);
        swap(b -= q*a, a);
    }
    return b;
}
 
template<typename T>
T mod_inv(T x, T m){
    T s, t;
    extgcd(x, m, s, t);
    return (m+s)% m;
}

poly inv (poly f){
    int n = f.size();
    vector<int> rr(1, mod_inv(f[0], MOD));
    poly r(rr);
    for (int k = 2; k <= n; k <<= 1) {
        vector<int> v(k);
        for (int i = 0; i < k; ++i) {
            v[i] = f[i];
        }
        poly ff(v);
        poly nr = (r*r);
        nr = nr*ff;
        nr.cut(k);
        for (int i = 0; i < k/2; ++i) {
            nr[i] = (2*r[i]-nr[i]+MOD)%MOD;
            nr[i+k/2] = (MOD-nr[i+k/2])%MOD;
        }
        r = nr;
    }
    return r;
}

int main() {
    int k, n;
    cin >> k >> n;
    int maxi = 0;
    vector<int> v(n);
    for (auto &&i : v) {
        scanf("%d", &i);
        maxi = max(maxi, i);
    }
    vector<int> p(1<<17, 0);
    for (int i = 0; i < n; ++i) {
        p[v[i]] = MOD-1;
    }
    p[0] = 1;
    poly pp(p);
    poly ppinv = inv(pp);
    cout << ppinv[k] << "\n";
    return 0;
}
