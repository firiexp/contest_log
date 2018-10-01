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

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    if(k == 0){
        cout << n*n << "\n";
        return 0;
    }

    for (ll b = k+1; b <= n; ++b) {
        ans += n/b*(b-k)+max(n%b-k+1, 0LL);
    }
    cout << ans << "\n";
    return 0;
}
