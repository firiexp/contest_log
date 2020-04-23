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

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

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
    string s;
    cin >> s;
    vector<ll> v(s.length()+1, 0), v2(s.length()+1, 0),
               v3(s.length()+1, 0), v4(s.length()+1, 0);
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A') v[i+1] = v[i]+1;
        else v[i+1] = v[i];
        if(s[i] == '?') v3[i+1] = v3[i]+1;
        else v3[i+1] = v3[i];
    }
    for (int j = static_cast<int>(s.length() - 1); j > 0; --j) {
        if(s[j] == 'C') v2[j-1] = v2[j]+1;
        else v2[j-1] = v2[j];
        if(s[j] == '?') v4[j-1] = v4[j]+1;
        else v4[j-1] = v4[j];
    }
    ll ans = 0;
    for (int k = 1; k < s.length()-1; ++k) {
        if(s[k] != 'B' && s[k] != '?') continue;
        ll p = ((((v[k]*3+v3[k])*(v2[k]*3+v4[k])) % MOD) * pow_(3, v3[k]+v4[k]-2, MOD)) % MOD;
        if(v3[k]+v4[k]-2 < 0){
            for (int i = 0; i < 2-v3[k]-v4[k]; ++i) {
                p /= 3;
            }
        }
        ans = (ans + p)%MOD;
    }
    cout << ans << "\n";
    return 0;
}
