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
#include <chrono>
static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

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


xor_shift rd;

template<int M>
class rolling_hash {

    static ll &B() {
        static ll B_ = rd.rand(2, M-1);
        return B_;
    }
    static vector<ll> &p() {
        static vector<ll> p_{1, B()};
        return p_;
    }
public:
    vector<ll> hash;
    explicit rolling_hash(const string &s) {
        if(p().size() <= s.size()){
            int l = p().size();
            p().resize(s.size()+1);
            for (int i = l; i < p().size(); ++i) {
                p()[i] = (p()[i-1]*p()[1])%M;
            }
        }
        hash.resize(s.size()+1, 0);
        for (int i = 0; i < s.size(); ++i) {
            hash[i+1] = (hash[i]*B() + s[i]) % M;
        }
    };

    ll get(int l, int r){
        ll res = hash[r]+M-hash[l]*p()[r-l]%M;
        return res >= M ? res-M : res;
    }
};

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

using mint = modint<MOD>;

int main() {
    string s;
    cin >> s;
    rolling_hash<MOD> h(s);
    rolling_hash<MOD+2> h2(s);
    int n = s.size(), m = n/2;
    vector<mint> dp(m+1);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(h.get(j, i+1) == h.get(n-i-1, n-j) && h2.get(j, i+1) == h2.get(n-i-1, n-j)) {
                dp[i+1] += dp[j];
            }
        }
    }
    cout << accumulate(dp.begin(),dp.end(), mint(0)).val << "\n";
    return 0;
}