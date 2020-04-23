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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    ll ans = 0;
    while(true){
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += v[i]/n;
        }
        if(sum == 0) break;
        for (int i = 0; i < n; ++i) {
            v[i] = sum - v[i]/n + v[i]%n;
        }
        ans += sum;
    }
    cout << ans << "\n";
    return 0;
}
