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
    ll n, k;
    cin >> n >> k;
    ll s = (ll)k*(k+1)/2;
    if(s > n) {
        puts("NO");
        return 0;
    }
    ll p = 0;
    if(k <= 30 && (1LL<<k)-1 < n){
        p = ((n-(1LL<<k)+1)/k);
    }
    vector<ll> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = p+i+1;
    }
    s += p*k;
    while(s < n){
        ll ss = s;
        for (int i = k-1; i >= 1; --i) {
            ll d = min({ans[i-1]*2-ans[i], n-s});
            s += d;
            ans[i] += d;
        }
    }
    puts("YES");
    for (int i = 0; i < k; ++i) {
        if(i) printf(" ");
        printf("%lli", ans[i]);
    }
    puts("");
    return 0;
}