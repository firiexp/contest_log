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
    int n, d;
    cin >> n >> d;
    ll ans = 0;
    vector<ll> v(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%lli", &v[i]);
    }
    v[n] = INF<ll>;
    sort(v.begin(),v.end());
    ll l = 0, r = 0;
    while(l < n && r <= n){
        while(v[r]-v[l] <= d) r++;
        ans += max(0LL, (r-l-1)*(r-l-2)/2);
        l++;
    }
    cout << ans << "\n";
    return 0;
}