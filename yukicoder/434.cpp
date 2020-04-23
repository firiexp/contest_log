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

static const int MOD = 9;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    const int m = 100000;
    vector<int> fact(m+1, 1), zeros(m+1, 0);
    array<int, 9> inv{0, 1, 5, 0, 7, 2, 0, 4, 8};
    iota(fact.begin(),fact.end(), 0);
    fact[0] = 1;
    for (int i = 3; i <= m; i *= 3) {
        for (int j = i; j <= m; j += i) {
            fact[j] /= 3;
            zeros[j]++;
        }
    }
    for (int i = 1; i < m; ++i) {
        zeros[i] = zeros[i-1]+zeros[i];
        fact[i] = fact[i-1]*fact[i]%MOD;
    }
    auto binom = [&](int n, int m){
        int z = zeros[n]-zeros[m]-zeros[n-m];
        if(z >= 2) return 0;
        return fact[n]*inv[fact[m]]*inv[fact[n-m]]*(z ? 3 : 1)%MOD;
    };
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(s == string(n, '0')) {
            puts("0");
            continue;
        }
        int ans = 8;
        for (int i = 0; i < n; ++i) {
            ans = (ans + binom(n-1, i)*(s[i]-'0'))%MOD;
        }
        printf("%d\n", ans+1);
    }
    return 0;
}