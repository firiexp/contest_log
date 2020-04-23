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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <ll M = MOD> struct modint {
public:
    ll val;
    explicit modint(const ll x = 0) : val(x) {}
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv(){
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n){
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return u;
    }
    modint &operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint &operator-=(const modint a){ val += a.val; if(val < 0) val += M; return *this; }
    modint &operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint &operator/=(const modint a){ val = (val*a.inv()) %M; return *this;}
};

using mint = modint<MOD>;

mint dp[1005][1005][3];

int main() {
    int n, m;
    cin >> n >> m;
    dp[0][0][0] = mint(1);
    vector<int> fizz(m+1), buzz(m+1);
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        if(s == "Fizz") fizz[i]++;
        else if(s == "Buzz") buzz[i]++;
        else fizz[i]++, buzz[i]++;
    }
    fizz[m]++;
    for (int j = 0; j <= m; ++j) {
        for (int k = 0; k < 3; ++k) {
            for (int p = 1; p < 10; ++p) {
                int isfizz = (k+p)%3 == 0, isbuzz = p%5 == 0;
                if(fizz[j] == isfizz && buzz[j] == isbuzz){
                    dp[1][j+1][(k+p)%3] += dp[0][j][k];
                }
                if(!isfizz && !isbuzz){
                    dp[1][j][(k+p)%3] += dp[0][j][k];
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int p = 0; p < 10; ++p) {
                    int isfizz = (k+p)%3 == 0, isbuzz = p%5 == 0;
                    if(fizz[j] == isfizz && buzz[j] == isbuzz){
                        dp[i+1][j+1][(k+p)%3] += dp[i][j][k];
                    }
                    if(!isfizz && !isbuzz){
                        dp[i+1][j][(k+p)%3] += dp[i][j][k];
                    }
                }
            }
        }
    }
    mint ans;
    for (int i = 0; i < 3; ++i) {
        ans += dp[n][m][i];
    }
    cout << ans.val << "\n";
    return 0;
}