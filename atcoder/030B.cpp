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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    ll l, n;
    cin >> l >> n;
    vector<ll> v(n);
    ll ans1 = 0, ans2 = 0;
    for (auto &&i : v) scanf("%lld", &i);

    if(n%2){
        vector<ll> u(n+1);
        u[0] = v[0];
        for (int i = 1; i < n; ++i) {
            u[i] = v[i] - v[i-1];
        }
        u[n] = l-v[n-1];
        ll k = n;
        for (int i = 0; i < (n+1)/2; ++i) {
            ans1 += u[i]*k+u[n-i]*(k-1);
            ans2 += u[i]*(k-1)+u[n-i]*k;
            k -= 2;
        }
    }else {
        vector<ll> u(n);
        u[0] = v[0];
        for (int i = 1; i <= n/2-1; ++i) {
            u[i] = v[i] - v[i-1];
            u[n/2+i-1] = v[n/2+i] - v[n/2+i-1];
        }
        ll k = n;
        u[n-1] = l-v[n-1];
        for (int i = 0; i < n/2; ++i) {
            ans1 += u[i]*k+u[n-i-1]*(k-1);
            ans2 += u[i]*(k-1)+u[n-i-1]*k;
            cout << ans1 << " " << ans2 << "\n";
            k -= 2;
        }
    }
    cout << max(ans1, ans2) << "\n";
    return 0;
}
