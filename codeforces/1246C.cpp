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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}



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

ostream& operator<<(ostream& os, mint p) {
    return os << p.val;
}


int main() {
    int n, m;
    cin >> n >> m;
    auto v1 = make_v(n+1, m, 0), v2 = make_v(n, m+1, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v1[i][j] = s[j] == 'R';
            v2[i][j] = s[j] == 'R';
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            v1[i][j] += v1[i+1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            v2[i][j] += v2[i][j+1];
        }
    }
    auto dp1 = make_v(n, m, mint(0));
    dp1[0][0] = 1;
    auto dp2 = dp1;
    if(n > 1){
        dp2[1][0] = -1;
    }
    if(m > 1){
        dp1[0][1] = -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i) dp2[i][j] += dp2[i-1][j];
            if(j) dp1[i][j] += dp1[i][j-1];
            if(i != n-1){ // go down(dp1 -> dp2)
                dp2[i+1][j] += dp1[i][j];
                if(v1[i+1][j]) dp2[n-v1[i+1][j]][j] -= dp1[i][j];
            }
            if(j != m-1){ // dp2 -> dp1
                dp1[i][j+1] += dp2[i][j];
                if(v2[i][j+1]) dp1[i][m-v2[i][j+1]] -= dp2[i][j];
            }

        }
    }
    cout << (dp1[n-1][m-1]+dp2[n-1][m-1]).val << "\n";
    return 0;
}