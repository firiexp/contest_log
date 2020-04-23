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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<ll>> v2(n+1, vector<ll>(30));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            v2[i+1][j] = v2[i][j] + ((v[i] >> j) & 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        for (int j = 0; j < 30; ++j) {
            ll a = v2[i+1][j], b = i+1-v2[i+1][j];
            ans += (1LL<<j)*((a-1)%2*a+a%2*b);
        }
        cout << ans << "\n";
    }
    return 0;
}