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

template<u32 M = 1000000007>
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

class Factorial {
    using mint = modint<MOD>;
    vector<mint> facts, factinv;

public:
    explicit Factorial(int n) : facts(static_cast<u32>(n+1)), factinv(static_cast<u32>(n+1)) {
        facts[0] = 1;
        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1]*mint(i);
        factinv[n] = facts[n].inv();
        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * mint(i+1);
    }

    mint fact(int k) const {
        if(k >= 0) return facts[k]; else return factinv[-k];
    }

    mint operator[](const int &k) const {
        if(k >= 0) return facts[k]; else return factinv[-k];
    }

    mint C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return facts[p] * factinv[q] * factinv[p-q];
    }

    mint P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return facts[p] * factinv[p-q];
    }

    mint H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return q == 0 ? 1 : C(p+q-1, q);
    }
};


using mint = modint<MOD>;

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

    void multi_mod(){
        for (int i = 0; i < N; ++i) {
            a[i] = num( A[i] & ((1LL << 15)-1),  A[i] >> 15);
        }
        for (int i = 0; i < N; ++i) {
            b[i] = num(B[i] & ((1LL << 15)-1), B[i] >> 15);
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
            C[i] = (aa + bb % MOD * (1LL << 15) + cc % MOD *(1LL << 30)) % MOD;
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

    void multi_mod(int n1, int n2){
        prepare_AB(n1, n2);
        multi_mod();
    }
}

struct poly {
    vector<mint> v;
    poly() = default;
    explicit poly(int n) : v(n) {};
    explicit poly(vector<mint> vv) : v(std::move(vv)) {};
    int size() const {return (int)v.size(); }
    poly cut(int len){
        if(len < v.size()) v.resize(static_cast<unsigned long>(len));
        return *this;
    }
    inline mint& operator[] (int i) {return v[i]; }
    poly& operator+=(const poly &a) {
        this->v.resize(max(size(), a.size()));
        for (int i = 0; i < a.size(); ++i) this->v[i] += a.v[i];
        return *this;
    }
    poly& operator-=(const poly &a) {
        this->v.resize(max(size(), a.size()));
        for (int i = 0; i < a.size(); ++i) this->v[i] -= a.v[i];
        return *this;
    }

    poly& operator*=(poly a) {
        for (int i = 0; i < size(); ++i) FFT::A[i] = this->v[i].val;
        for (int i = 0; i < a.size(); ++i) FFT::B[i] = a.v[i].val;
        FFT::multi_mod(size(), a.size());
        this->v.resize(size() + a.size()-1);
        for (int i = 0; i < size(); ++i) this->v[i] = FFT::C[i];
        return *this;
    }
    poly& operator/=(const poly &a){ return (*this *= a.inv()); }
    poly operator+(const poly &a) const { return poly(*this) += a; }
    poly operator-(const poly &a) const { return poly(*this) -= a; }
    poly operator*(const poly &a) const { return poly(*this) *= a; }

    poly inv() const {
        int n = size();
        poly r(1);
        r[0] = (this->v[0]).inv();
        int k = 1;
        while(k < n){
            k *= 2;
            poly ff(k);
            for (int i = 0; i < min(k, n); ++i) {
                ff[i] = this->v[i];
            }
            poly nr = (r*r*ff).cut(k);
            for (int i = 0; i < k/2; ++i) {
                nr[i] = (r[i]+r[i]-nr[i]);
                nr[i+k/2] = -nr[i+k/2];
            }
            r = nr;
        }
        r.v.resize(n);
        return r;
    }
};

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
    vector<mint> pow2(n+1, mint(1));
    for (int i = 0; i < n; ++i) {
        pow2[i+1] = pow2[i] + pow2[i];
    }
    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        if(G[i].size() == 1) continue;
        mint val = pow2[n-1] - mint(1);
        for (auto &&j : G[i]) {
            if(num[i] < num[j]) {
                val -= (pow2[v[j]]-mint(1));
            } else {
                val -= (pow2[n - v[i]] - mint(1));
            }
        }
        ans += val;
    }
    ans /= pow2[n];
    cout << ans.val << "\n";
    return 0;
}