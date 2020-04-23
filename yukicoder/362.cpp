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

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

string solve(ll x){
    auto dp1 = make_v(20, 10, 10, 0LL); // i+1桁の数で、かつ上の2桁がj, kである数
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(i != j) dp1[1][i][j] = 1;
        }
    }
    ll n = 0;
    for (int i = 2; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if(!dp1[i-1][j][k]) continue;
                for (int l = 0; l < 10; ++l) {
                    if(IsKadomatsu(l, j, k)){
                        dp1[i][l][j] += dp1[i-1][j][k];
                    }
                }
            }
        }
        ll s = 0;
        for (int j = 1; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                s += dp1[i][j][k];
            }
        }
        if(s >= x){
            n = i; break;
        }
        x -= s;
    }
    int a = 0, b = 0;
    string ans;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(dp1[n][i][j] < x) x -= dp1[n][i][j];
            else {
                a = i, b = j;
                ans += to_string(i);
                ans += to_string(j);
                i = 10, j = 10; break;
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < 10; ++j) {
            if(IsKadomatsu(a, b, j)){
                if(dp1[i][b][j] < x)  x -= dp1[i][b][j];
                else {
                    a = b, b = j;
                    ans += to_string(j);
                    break;
                }
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}