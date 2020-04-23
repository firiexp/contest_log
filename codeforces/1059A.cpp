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
    int n, l, a;
    cin >> n >> l >> a;
    vector<pair<int, int>> v;
    v.emplace_back(-1, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v.emplace_back(x, x+y);
    }
    v.emplace_back(l, l+1);
    ll ans = 0;
    for (int i = 0; i < n+1; ++i) {
        ans += (v[i+1].first-v[i].second)/a;
    }
    cout << ans << "\n";
    return 0;
}
