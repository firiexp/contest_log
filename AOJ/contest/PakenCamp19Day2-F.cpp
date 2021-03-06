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
using mint = modint<MOD>;

int main() {
    int n;
    cin >> n;
    vector<int> dp(1 << 20);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        dp[x]++;
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < (1 << 20); ++j) {
            if(!(j & (1 << i))) dp[j] += dp[j^(1 << i)];
        }
    }
    vector<mint> mul2(n+1);
    mul2[0] = 1;
    for (int i = 0; i < n; ++i) {
        mul2[i+1] = mul2[i]+mul2[i];
    }
    mint ans = 0;
    for (int i = 0; i < (1 << 20); ++i) {
        if(__builtin_popcount(i)&1) ans -= mul2[dp[i]];
        else ans += mul2[dp[i]];
    }
    cout << ans.val << "\n";
    return 0;
}