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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    vector<int> v2;
    v2.reserve(m - 1);
    for (int i = 0; i < m-1; ++i) {
        v2.emplace_back(v[i+1]-v[i]);
    }
    sort(v2.begin(), v2.end());
    int ans = 0;
    for (int i = 0; i < m-n; ++i) {
        ans += v2[i];
    }
    cout << ans << "\n";
    return 0;
}
