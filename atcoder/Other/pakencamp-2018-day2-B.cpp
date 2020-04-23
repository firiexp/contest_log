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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end(), greater<>());
    int ans = 0;
    for (int j = d-1; j < n; j += d) {
        ans += v[j];
    }
    cout << ans << "\n";
    return 0;
}
