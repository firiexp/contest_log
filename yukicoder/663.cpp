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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

template <ll M = MOD> struct modint {
    ll val;
    modint(const ll x = 0) : val(x) {
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
    }

    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv() const {
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n) const {
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return modint(u);
    }
    modint& operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint& operator-=(const modint a){ val -= a.val; if(val < 0) val += M; return *this; }
    modint& operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint& operator/=(const modint a){ val = val * a.inv().val % M; return *this;}

    modint& operator=(const int& x){
        val = x;
        while(val < 0) val += M;
        while(val > M) val -= M;
        return *this;
    }
};

using mint = modint<MOD>;

using ar = array<int, 3>;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto dp = make_v(n, 2, 2, 2, 2, 2, mint(0));

    vector<array<int, 3>>  a{{0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}},
    b {{0, 0, 0}, {1, 0, 0}, {1, 1, 1}};
    if(v[0]){
        for (auto &&i : a) {
            dp[0][i[0]][i[1]][i[0]][i[1]][i[2]] = 1;
        }
    }else {
        for (auto &&i : b) {
            dp[0][i[0]][i[1]][i[0]][i[1]][i[2]] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        for (int p = 0; p < 2; ++p) {
                            for (int q = 0; q < 2; ++q) {
                                if(v[i]){
                                    if(count(a.begin(),a.end(), ar{m, p, q})){
                                        dp[i][j][k][m][p][q] += dp[i-1][j][k][l][m][p];
                                    }
                                }else {
                                    if(count(b.begin(),b.end(), ar{m, p, q})){
                                        dp[i][j][k][m][p][q] += dp[i-1][j][k][l][m][p];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    mint ans = 0;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                ans += dp[n-1][k][l][j][k][l];
            }
        }
    }
    cout << ans.val << "\n";
    return 0;
}