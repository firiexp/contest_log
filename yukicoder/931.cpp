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

static const int MOD = 998244353;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

#include <chrono>
class xor_shift {
    uint32_t x, y, z, w;
public:
    xor_shift() : x(static_cast<uint32_t>((chrono::system_clock::now().time_since_epoch().count())&((1LL << 32)-1))),
    y(1068246329), z(321908594), w(1234567890) {};

    uint32_t urand(){
        uint32_t t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    };

    int rand(int n){
        if(n < 0) return -rand(-n);
        uint32_t t = numeric_limits<uint32_t>::max()/(n+1)*(n+1);
        uint32_t e = urand();
        while(e >= t) e = urand();
        return static_cast<int>(e%(n+1));
    }

    int rand(int a, int b){
        if(a > b) swap(a, b);
        return a+rand(b-a);
    }
};

constexpr int ntt_mod = 998244353, ntt_root = 3;
// 1012924417 -> 5, 924844033 -> 5
// 998244353  -> 3, 897581057 -> 3
// 645922817  -> 3;

template<int M, int proot>
class NTT {
    vector<vector<int>> rts, rrts;
public:
    NTT() = default;

    inline int add(int a,int b){ a += b; if(a >= M) a -= M; return a; }

    inline int mul(int a,int b){ return 1LL * a * b % M; }

    inline int pow(int a,int b){
        int res = 1;
        while(b){
            if(b&1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    inline int extgcd(int a, int b, int &x ,int &y){
        for (int u = y = 1, v = x = 0; a; ) {
            ll q = b/a;
            swap(x -= q*u, u);
            swap(y -= q*v, v);
            swap(b -= q*a, a);
        }
        return b;
    }
    inline int inv(int x){
        int s, t;
        extgcd(x, M, s, t);
        return (M+s)%M;
    }

    void ensure_base(int N) {
        if(rts.size() >= N) return;
        rts.resize(N), rrts.resize(N);
        for(int i = 1; i < N; i <<= 1) {
            if(!rts[i].empty()) continue;
            int w = pow(proot, (M - 1) / (i << 1));
            int rw = inv(w);
            rts[i].resize(i), rrts[i].resize(i);
            rts[i][0] = 1, rrts[i][0] = 1;
            for(int k = 1; k < i; k++) {
                rts[i][k] = mul(rts[i][k - 1],w);
                rrts[i][k] = mul(rrts[i][k - 1],rw);
            }
        }
    }
    void ntt(vector<int> &a, int sign){
        int n = a.size();
        ensure_base(n);

        for (int i = 0, j = 1; j < n-1; ++j) {
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if(j < i) swap(a[i], a[j]);
        }
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += i * 2) {
                for (int k = 0; k < i; ++k) {
                    int y = mul(a[j+k+i], (sign ? rrts[i][k] : rts[i][k]));
                    a[j+k+i] = add(a[j+k], M-y), a[j+k] = add(a[j+k], y) ;
                }
            }
        }
        if(sign) {
            int temp = inv(n);
            for (int i = 0; i < n; ++i) a[i] = mul(a[i],temp);
        }
    }
};



NTT<ntt_mod, ntt_root> ntt;

constexpr int M = ntt_mod;

struct poly {
    vector<int> v;
    poly() = default;
    explicit poly(int n) : v(n) {};
    explicit poly(vector<int> vv) : v(std::move(vv)) {};
    int size() const {return (int)v.size(); }
    poly cut(int len){
        if(len < v.size()) v.resize(static_cast<unsigned long>(len));
        return *this;
    }
    inline int& operator[] (int i) {return v[i]; }
    poly operator+(const poly &a) const { return poly(*this) += a; }
    poly operator-(const poly &a) const { return poly(*this) -= a; }
    poly operator*(const poly &a) const { return poly(*this) *= a; }

    poly inv() const {
        int n = size();
        vector<int> rr(1, ntt.inv(this->v[0]));
        poly r(rr);
        for (int k = 2; k <= n; k <<= 1) {
            vector<int> u(k);
            for (int i = 0; i < k; ++i) {
                u[i] = this->v[i];
            }
            poly ff(u);
            poly nr = (r*r);
            nr = nr*ff;
            nr.cut(k);
            for (int i = 0; i < k/2; ++i) {
                nr[i] = (2*r[i]-nr[i]+M)%M;
                nr[i+k/2] = (M-nr[i+k/2])%M;
            }
            r = nr;
        }
        r.v.resize(n);
        return r;
    }

    poly& operator+=(const poly &a) {
        this->v.resize(max(size(), a.size()));
        for (int i = 0; i < a.size(); ++i) {
            (this->v[i] += a.v[i]);
            if(this->v[i] > ntt_mod) this->v[i] -= M;
        }
        return *this;
    }
    poly& operator-=(const poly &a) {
        this->v.resize(max(size(), a.size()));
        for (int i = 0; i < a.size(); ++i) {
            (this->v[i] += M-a.v[i]);
            if(this->v[i] > M) this->v[i] -= M;
        }
        return *this;
    }

    poly& operator*=(poly a) {
        int N = size()+a.size()-1;
        int sz = 1;
        while(sz < N) sz <<= 1;
        ntt.ensure_base(sz);
        this->v.resize(sz); a.v.resize(sz);
        ntt.ntt(this->v, 0); ntt.ntt(a.v, 0);
        for(int i = 0; i < sz; ++i) this->v[i] = ntt.mul(this->v[i], a.v[i]);
        ntt.ntt(this->v, 1);
        this->cut(N);
        return *this;
    }

    poly& operator/=(const poly &a){
        return (*this *= a.inv());
    }
};

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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i % j == 0) break;
        }
    }
    return prime;
}
const auto primes = get_prime(1000);

template<class T>
vector<T> prime_factor(T n){
    vector<T> res;
    for (auto &&i : primes) {
        while (n % i == 0){
            res.emplace_back(i);
            n /= i;
        }
    }
    if(n != 1) res.emplace_back(n);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}


int main() {
    int p;
    cin >> p;
    if(p == 2){
        ll x, y;
        cin >> x >> y;
        cout << x*y%MOD << "\n";
        return 0;
    }
    xor_shift rd;
    int g = rd.rand(2, p-1);
    auto ps = prime_factor(p-1);
    while(true){
        int ok = 1;
        for (auto &&i : ps) {
            if(pow_(g, (p-1)/i, p) == 1){
                ok = false;
            }
        }
        if(ok) break;
        g = rd.rand(2, p-1);
    }
    vector<ll> gs(p*2+1, 1);
    for (int i = 1; i < 2*p; ++i) {
        gs[i] = gs[i-1]*g % p;
    }
    poly A(p-1), B(p-1);
    vector<int> a(p), b(p);
    for (int i = 1; i < p; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < p; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < p-1; ++i) {
        A[i] = a[gs[i]];
        B[i] = b[gs[i]];
    }
    auto C = A*B;
    vector<int> ans(p);
    for (int i = 0; i < C.size(); ++i) {
        ans[gs[i]] += C[i];
        if(ans[gs[i]] > MOD) ans[gs[i]] -= MOD;
    }
    for (int i = 0; i < p-1; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i+1]);
    }
    puts("");
    return 0;
}