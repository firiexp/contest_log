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
    int n, h, w;
    cin >> n >> h >> w;
    vector<ll> v(2*n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if(i&1) v[i] = i*w-x, v[i+n] = (i+1)*w-x+MOD;
        else v[i] = i*w+x, v[i+n] = (i+1)*w+x+MOD;
    }
    sort(v.begin(),v.end(), [&](ll x, ll y){ return x%MOD < y%MOD;});
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < 2*n; ++i) {
        if(v[i] >= MOD) v[i] %= MOD, cnt--;
        else cnt++;
        if(cnt > 0){
            ans += (v[i+1]-v[i]+MOD*2)%MOD;
        }
    }
    cout << (w*n-ans)*h << "\n";
    return 0;
}