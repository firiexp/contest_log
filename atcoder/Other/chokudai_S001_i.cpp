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

int main() {
    int n;
    cin >> n;
    vector<ll> v(n), S(n+1);
    for (auto &&i : v) scanf("%lld", &i);
    map<ll, int> m;
    ll ans = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + v[i];
        ans += m[S[i+1]-n];
        m[S[i+1]]++;
    }
    cout << ans << "\n";
    return 0;
}