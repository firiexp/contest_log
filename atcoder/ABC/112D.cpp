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

vector< ll > divisor(ll n)
{
    vector< ll > ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v = divisor((ll)m);
    sort(v.begin(), v.end());
    ll ans = 1;
    for (auto &&i : v) {
        if(n <= m/i) ans = max(ans, i);
    }
    cout << ans << "\n";
    return 0;
}
