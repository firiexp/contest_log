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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> val(n);
    for (int i = 0; i < n; ++i) {
        val[i] = v[i]%(a+b);
        if(!val[i]) val[i] = (b-1)/a+1;
        else val[i] = (val[i]-1)/a;
        // cout << i+1 << " " << val[i] << "!\n";
    }
    sort(val.begin(),val.end());
    ll ans = 0, vall = 0;
    for (int i = 0; i < n; ++i) {
        if(vall+val[i] <= k){
            ans++;
            vall += val[i];
        }
    }
    cout << ans << "\n";
    return 0;
}