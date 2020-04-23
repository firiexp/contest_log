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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

mint dp1[200001][2];
mint dp2[200001][3];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v, v2;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(i&1) v.emplace_back(x);
        else v2.emplace_back(x);
    }
    dp1[0][0] = 1;
    dp2[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        dp1[i+1][0] = dp1[i][1];
        dp1[i+1][1] = dp1[i][0]*mint(k-1)+dp1[i][1]*mint(k-2);
        dp2[i+1][0] = dp2[i][1] + dp2[i][2];
        dp2[i+1][1] = dp2[i][0] + dp2[i][2];
        dp2[i+1][2] = dp2[i][0]*mint(k-2) + dp2[i][1]*mint(k-2) + dp2[i][2]*mint(max(0, k-3));
    }
    auto solve = [&](vector<int> &a) -> mint {
        vector<pair<int, int>> rle;
        rle.emplace_back(a[0], 1);
        for (int i = 1; i < a.size(); ++i) {
            if(rle.back().first == a[i]) rle.back().second++;
            else rle.emplace_back(a[i], 1);
        }
        mint ans = 1;
        if(rle.size() == 1){
            if(rle.back().first != -1) {
                if(rle.back().second != 1) return {0};
                else return {1};
            } else return mint(k)*(mint(k-1).pow(rle.back().second-1));
        }
        if(rle.front().first == -1){
            ans *= mint(k-1).pow(rle.front().second);
            rle = vector<pair<int, int>>(rle.begin()+1,rle.end());
        }
        if(rle.back().first == -1){
            ans *= mint(k-1).pow(rle.back().second);
            rle.pop_back();
        }

        for (int i = 0; i < rle.size(); ++i) {
            if(rle[i].first != -1){
                if(rle[i].second != 1) return {0};
            }else {
                if(rle[i-1].first == rle[i+1].first) ans *= dp1[rle[i].second][1];
                else {
                    ans *= dp2[rle[i].second][0]+dp2[rle[i].second][2];
                }
            }
        }
        return ans;
    };
    cout << (solve(v)*solve(v2)).val << "\n";
    return 0;
}