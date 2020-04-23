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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    auto dp = make_v(n, n+1, mint(0));
    auto dq = dp;
    vector<int> sz(n, 1);
    vector<mint> a(n+1), b(n+1);
    auto dfs = [&](int x, int par, auto &&f) -> void {
        dp[x][0] = dq[x][1] = 1;
        for (auto &&y : G[x]) {
            if(y != par) {
                f(y, x, f);
                fill(a.begin(), a.begin()+sz[x]+sz[y]+1, mint(0));
                fill(b.begin(), b.begin()+sz[x]+sz[y]+1, mint(0));
                for (int i = 0; i <= sz[x]; ++i) {
                    for (int j = 0; j <= sz[y]; ++j) {
                        a[i+j] += dp[x][i]*dp[y][j] + dp[x][i]*dq[y][j];
                        b[i+j] += dq[x][i]*dq[y][j];
                    }
                }
                sz[x] += sz[y];
                for (int i = 0; i <= sz[x]; ++i) {
                    dp[x][i] = a[i];
                    dq[x][i] = b[i];
                }
            }
        }
    };
    dfs(0, -1, dfs);
    cout << (dp[0][k]+dq[0][k]).val << "\n";
    return 0;
}