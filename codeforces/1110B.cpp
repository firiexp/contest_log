#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u;
    ll ans = v[n-1]-v[0]+1, p = k;
    for (int i = 0; i < n-1; ++i) {
        u.emplace_back(v[i+1]-v[i]-1);
    }
    sort(u.begin(), u.end(), greater<>());
    for (int j = 0; j < k-1; ++j) {
        ans -= u[j];
    }
    cout << ans << "\n";
    return 0;
}
