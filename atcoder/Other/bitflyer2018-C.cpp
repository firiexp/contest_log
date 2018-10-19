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
    int n, d;
    cin >> n >> d;
    vector<int> l(n), r(n), v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        l[i] = static_cast<int>(i - (lower_bound(v.begin(), v.end(), v[i] - d) - v.begin()));
        r[i] = static_cast<int>(upper_bound(v.begin(), v.end(), v[i] + d) - v.begin() - 1 - i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(r[i] > 1){
            ans -= (ll)r[i]*(r[i]-1)/2;
        }
        ans += (ll)l[i]*r[i];
    }
    cout << ans << "\n";
    return 0;
}
