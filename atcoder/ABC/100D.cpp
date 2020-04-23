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

int main() {
    vector<vector<ll>> v(8);
    int n, m;
    cin >> n >> m;
    for (int x = 0; x < n; ++x) {
        ll a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    v[i+j*2+k*4].emplace_back(a*(1-2*i)+b*(1-2*j)+c*(1-2*k));
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 8; ++i) {
        sort(v[i].begin(), v[i].end(), greater<>());
        ll k = 0;
        for (int j = 0; j < m; ++j) {
            k += v[i][j];
        }
        ans = max(k, ans);
    }
    cout << ans << "\n";
    return 0;
}
