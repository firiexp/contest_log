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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<mint> a(31);
    a[0] = 1;
    for (int i = 0; i < 30; ++i) {
        a[i+1] = a[i]*mint(10);
    }
    array<array<int, 11>, 11> val{};
    array<int, 11> cnt{};
    vector<int> t;
    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        while(!t.empty()) t.pop_back();
        while(v[i]){
            t.emplace_back(v[i]%10);
            v[i] /= 10;
        }
        int cur = 0;
        cnt[t.size()]++;
        for (int j = 0; j < t.size(); ++j) {
            val[t.size()][j] += t[j];
            // ans -= mint(t[j])*a[cur++];
            // ans -= mint(t[j])*a[cur++];
        }

    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            int cur = 0;
            mint tmp1 = 0, tmp2 = 0;
            for (int k = 0; k < 10; ++k) {
                if(k < i) tmp1 += mint(val[i][k])*a[cur++];
                if(k < j) tmp2 += mint(val[j][k])*a[cur++];
            }
            ans += tmp1*mint(cnt[j])+tmp2*mint(cnt[i]);
        }
    }
    cout << ans.val << "\n";
    return 0;
}