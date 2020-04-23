#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

ll pow_ (ll x, ll n, ll M){
    ll u = 1;
    if(n > 0){
        u = pow_(x, n/2, M);
        if (n % 2 == 0) u = (u*u) % M;
        else u = (((u * u)% M) * x) % M;
    }
    return u;
};

int main() {
    int n, p;
    cin >> n >> p;
    ll odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        (k % 2 ? odd : even)++;
    }
    ll ans;
    if(!p){
        if(odd == 0) ans = pow_(2, odd+even, numeric_limits<ll>::max());
        else ans = pow_(2, odd+even-1, numeric_limits<ll>::max());
    }else {
        if(odd == 0) ans = 0;
        else {
            ans = pow_(2, odd+even-1, numeric_limits<ll>::max());
        }
    }
    cout << ans << "\n";
    return 0;
}
