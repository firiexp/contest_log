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
    vector<ll> v(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] < 0) k++, v[i] = -v[i];
    }
    sort(v.begin(),v.end());
    ll ans = k%2 ? -v[0]*2 : 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i];
    }
    cout << ans << "\n";
    return 0;
}