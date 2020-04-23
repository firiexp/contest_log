#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 924844033;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

template <class T> class Factorial {
    T mod;
    vector<uint64_t> facts, factinv;

public:
    Factorial(int n, T mod) : facts(static_cast<u32>(n+1)), factinv(static_cast<u32>(n+1)), mod(mod) {
        facts[0] = 1;
        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1]*i % mod;
        factinv[n] = pow_(facts[n], static_cast<uint64_t>(mod - 2), static_cast<uint64_t>(mod));
        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * (i+1) % mod;
    }

    T fact(int k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T operator[](const int &k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>(facts[p]*  factinv[q] % mod * factinv[p-q] % mod);
    }

    T P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>((facts[p] * factinv[p-q]) % mod);
    }

    T H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return static_cast<T>(q == 0 ? 1 : C(p+q-1, q));
    }
};

#include <cmath>
namespace FFT {
    const int max_base = 19, maxN = 1 << max_base; // N <= 2e5
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
    array<num, maxN> root;
    array<int, maxN> rev;
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

    void fft(array<num, maxN> &a, array<num, maxN> &f){
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
    array<num, maxN> a, b, f, g;
    array<ll, maxN> A, B, C;

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


int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    deque<int> Q;
    vector<int> num(n);
    {
        stack<int> s;
        int cnt = 0;
        vector<int> visited(n, 0);
        s.emplace(0);
        while(!s.empty()){
            int a = s.top(); s.pop();
            visited[a]++;
            num[a] = cnt++;
            Q.emplace_front(a);
            for (auto &&i : G[a]) {
                if(!visited[i]) s.emplace(i);
            }
        }
    }
    vector<int> v(n, 1);
    vector<int> u(n+1);
    while(!Q.empty()){
        int i = Q.front(); Q.pop_front();
        for (auto &&j : G[i]) {
            if(num[i] < num[j]) v[i] += v[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &&j : G[i]) {
            if(i < j){
                int p = min(v[i], v[j]);
                u[p]++; u[n-p]++;
            }
        }
    }
    Factorial<ll> fact(n, MOD);
    for (int i = 0; i <= n; ++i) {
        u[i] = static_cast<int>((fact[i] * u[i]) % MOD);
    }
    vector<int> uu(n+1);
    for (int i = 0; i <= n; ++i) {
        uu[i] = static_cast<int>(fact[i-n]);
    }
    poly f(u), g(uu);
    poly h = f*g;
    for (int k = 1; k <= n; ++k) {
        ll ans = (fact.C(n, k)*n%MOD + (MOD - fact[-k]*h[n+k]%MOD)) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
