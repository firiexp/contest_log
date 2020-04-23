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

static const int MOD = 1000000009;
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
    int n, k;
    cin >> n >> k;
    vector<int> cnt1(k);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        for (int j = 0; j < k; ++j) {
            if(x & (1LL << j)){
                cnt1[j]++;
            }
        }
    }
    mint Ex, Exx, tmp = 1;
    mint A = mint(2).pow(k)-mint(1);
    Ex = mint(n)*A*mint(500000005);
    Exx = A*A;
    for (int i = 0; i < k; ++i) {
        Exx -= tmp*tmp;
        tmp += tmp;
    }
    Exx *= mint(n)*mint(n)*mint(750000007);
    tmp = 1;
    mint tmp2;
    for (int i = 0; i < k; ++i) {
        tmp2 += tmp*tmp*(mint(cnt1[i]).pow(2)+mint(n-cnt1[i]).pow(2));
        tmp += tmp;
    }
    Exx += tmp2*mint(500000005);
    mint ans1 = Ex*(mint(2).pow(k));
    mint ans2 = (Exx-Ex*Ex)*(mint(4).pow(k));
    cout << ans1.val << "\n";
    cout << ans2.val << "\n";
    return 0;
}