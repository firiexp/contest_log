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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(b+2);
    for (int i = 0; i < b; ++i) {
        scanf("%lli", &v[i+1]);
    }
    v[b+1] = n+1;
    sort(v.begin(),v.end());
    ll ans = 0;
    for (int i = 0; i <= b; ++i) {
        if(v[i+1] != v[i]) ans += (v[i+1]-v[i]-1)/a*(a-1)+(v[i+1]-v[i]-1)%a;
    }
    cout << ans << "\n";
    return 0;
}