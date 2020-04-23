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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> A(n+1), B(n+1);
    for (int i = 0; i < n; ++i) {
        A[i+1] = A[i] + v[i];
    }
    for (int j = n-1; j >= 0; --j) {
        B[j] = B[j+1] + v[j];
    }
    ll ans = INF<ll>;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, abs(A[i]-B[i]));
    }
    cout << ans << "\n";
    return 0;
}