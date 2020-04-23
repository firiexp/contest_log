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
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    vector<ll> S(n+1), A(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + v[i].second;
        A[i+1] = max(A[i], v[i].first);
    }
    ll ans = 0, M = S[n]-A[n];
    for (int i = n-1; i >= 0; --i) {
        ans = max(ans, M-S[i]+A[i+1]);
        M = max(M, S[i]-A[i]);
    }
    cout << ans << "\n";
    return 0;
}