#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int n;
    cin >> n;
    vector<ll> u(n), v(n+1, 0);
    for (auto &&i : u) scanf("%lld", &i);
    partial_sum(u.begin(), u.end(), v.begin()+1);
    ll ans = INF<ll>;
    int l = 1, r = 4;
    for (int i = 2; i < n-1; ++i) {
        l--, r--;
        if(r <= i) r = i+1;
        if(l >= i) l = i-1;
        while(l < i && v[i] > 2*v[l]) l++;
        while(r < n && v[n]+v[i] > 2*v[r]) r++;
        for (int j = 0; j < 2 && l > j; ++j) {
            for (int k = 0; k < 2 && r > i; ++k) {
                ans = min(ans, max({v[l-j], v[i]-v[l-j], v[r-k]-v[i], v[n]-v[r-k]})-
                               min({v[l-j], v[i]-v[l-j], v[r-k]-v[i], v[n]-v[r-k]}));
            }
        }

    }
    cout << ans << "\n";
    return 0;
}
