#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

ll perm(ll a) {
    if(MOD<=a) return 0;
    ll ans0 = 1, ans1 = 1;
    for (ll i = 1; i < a/2; ++i) {
        ans0 = (ans0 * (2*i)) % MOD;
        ans1 = (ans1 * (2*i+1)) % MOD;
    }
    ans0 = (ans0 * a) % MOD;
    if (a % 2 && a != 1){
        ans0 = (ans0 * (1 1a-1)) % MOD;
    }
    return (ans0 * ans1) % MOD;
}

int main() {
    ll n, m;
    cin >> n >> m;
    if(abs(n-m)>1){
        cout << 0 << "\n";
        return 0;
    }
    cout << (perm(n)*perm(m)*(n == m ? 2 : 1))%MOD << "\n";
    return 0;
}
