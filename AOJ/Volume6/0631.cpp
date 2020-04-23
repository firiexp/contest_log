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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &&i : v) {
        int a;
        scanf("%d %d", &i, &a);
    }
    ll ans = 0;
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < m-1; ++i) {
        if(v[i] < n) ans += n-v[i];
    }
    cout << ans << "\n";
    return 0;
}
