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
using mint = modint<MOD>;

int main() {
    using B = bitset<4000>;
    auto f = [&](string &s) -> B {
        B res;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') res.set(4000+i-(int)s.size());
        }
        return res;
    };
    int n; B X;
    cin >> n;
    vector<B> v(n);
    {
        string x;
        cin >> x;
        X = f(x);
        for (int i = 0; i < n; ++i) cin >> x, v[i] = f(x);
    }
    for (int i = 1; i < n; ++i) {
        int a = v[0]._Find_first(), b = v[i]._Find_first();

        while(true){
            if(a == 4000 || b == 4000) {
                if(a == 4000) swap(v[0], v[i]);
                break;
            }
            if(a > b){
                v[i] ^= (v[0] >> (a-b));
                b = v[i]._Find_first();
            }else {
                v[0] ^= (v[i] >> (b-a));
                a = v[0]._Find_first();
            }
        }
    }

    int a = v[0]._Find_first(), b = X._Find_first();
    B Y;
    mint ans = 0;
    for (int i = b; i <= a; ++i) {
        if(X[i]) {
            ans += mint(2).pow(a-i);
        }
        if(X[i] != Y[i]){
            Y ^= (v[0] >> (a-i));
        }
    }
    int ok = 1;
    for (int i = 0; i < 4000; ++i) {
        if(!X[i] && Y[i]) {
            ok = 0;
            break;
        } else if(X[i] && !Y[i]) break;
    }
    if(ok) ans += mint(1);
    cout << ans.val << "\n";
    return 0;
}