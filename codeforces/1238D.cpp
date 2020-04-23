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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = n*(n-1)/2;
    vector<ll> dp(n+1), dp2(n+1);
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
        if(s[i-1] == s[i]) dp[i+1] = dp[i] + 1;
        else dp[i+1] = 1;
    }
    dp2[n-1] = 1;
    for (int j = n-2; j >= 0; --j) {
        if(s[j+1] == s[j]) dp2[j] = dp2[j+1] + 1;
        else dp2[j] = 1;
    }
    for (int i = 0; i < n-1; ++i) {
        if(s[i] != s[i+1]) ans -= dp[i+1]+dp2[i+1]-1;
    }
    cout << ans << "\n";
    return 0;
}