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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), u(m);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    u.emplace_back(-INF<int>);
    u.emplace_back(INF<int>);
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    vector<ll> S(n), T(n+1);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while(u[cur+1] < v[i]) cur++;
        S[i] = cur;
    }
    cur = m+1;
    for (int i = n-1; i >= 0; --i) {
        while(v[i] < u[cur-1]) cur--;
        T[i] = T[i+1]+m+1-cur;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        (ans += S[i]*T[i+1]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}