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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    for (int j = n-2; j >= 0; --j) {
        v[j] = v[j+1]+v[j];
    }
    ll ans = v[0];
    sort(v.begin()+1,v.end(), greater<>());
    for (int i = 1; i < k; ++i) {
        ans += v[i];
    }
    cout << ans << "\n";
    return 0;
}