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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end(), greater<>());
    ll ans = v[0].first*(v[0].second+x);
    for (int i = 1; i < n; ++i) {
        ans += v[i].first*v[i].second;
    }
    cout << ans << "\n";
    return 0;
}
