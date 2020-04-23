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


ll pow_ (ll x, ll n){
    if (x <= 0) return 0;
    ll u = 1;
    if(n > 0){
        u = pow_(x, n/2);
        if (n % 2 == 0) u = (u*u);
        else u = (((u * u)) * x);
    }
    return u;
};

int main() {
    ll n, k;

    cin >> n >> k;
    ll ans = pow_(n/k, 3);
    if(k%2 == 0) ans += pow_((n+k/2)/k, 3);
    cout << ans << "\n";
    return 0;
}
