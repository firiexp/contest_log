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

mint ans[52][52];
int main() {
    array<int, 256> c{};
    for (int i = 0; i < 26; ++i) {
        c[i+'a'] = i;
        c[i+'A'] = i+26;
    }
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n), cnt(52);
    for (int i = 0; i < n; ++i) {
        v[i] = c[s[i]];
        cnt[v[i]]++;
    }
    Factorial f(n);
    mint coeff = f[n/2]*f[n/2];
    for (int i = 0; i < 52; ++i) {
        coeff *= f[-cnt[i]];
    }
    vector<mint> dp(n+1), dp2(n+1);
    dp[0] = 1;
    for (int i = 0; i < 52; ++i) {
        if(cnt[i]) for (int k = n-cnt[i]; k >= 0; --k) dp[k+cnt[i]] += dp[k];
    }
    for (int i = 0; i < 52; ++i) {
        if(!cnt[i]) continue;
        copy(dp.begin(),dp.end(), dp2.begin());
        for (int k = 0; k <= n-cnt[i]; ++k) dp2[k+cnt[i]] -= dp2[k];
        ans[i][i] = dp2[n/2]*coeff*mint(2);
        for (int j = i+1; j < 52; ++j) {
            if(!cnt[j]) continue;
            for (int k = 0; k <= n-cnt[j]; ++k) dp2[k+cnt[j]] -= dp2[k];
            ans[i][j] = dp2[n/2]*coeff*mint(2);
            for (int k = n-cnt[j]; k >= 0; --k) dp2[k+cnt[j]] += dp2[k];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = v[a-1]; b = v[b-1];
        if(a > b) swap(a, b);
        printf("%d\n", ans[a][b].val);
    }
    return 0;
}