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
    vector<ll> A(n), B(n);
    for (auto &&i : A) scanf("%lld", &i);
    for (auto &&j : B) scanf("%lld", &j);
    for (int i = 0; i < n-1; ++i) {
        A[i+1] += A[i];
    }
    ll ans = INF<ll>;
    for (int i = 0; i < n; ++i) {
        if(A[i] >= B[i] && ans >= B[i]){
            ans = B[i];
        }
    }
    if(ans == INF<ll>) puts("-1");
    else cout << ans << "\n";
    return 0;
}