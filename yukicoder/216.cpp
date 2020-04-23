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
    vector<int> v(n, 0), v1(n, 0), v2(101, 0);
    for (auto &&i : v) cin >> i;
    for (auto &&j : v1) cin >> j;
    for (int i = 0; i < n; ++i) {
        v2[v1[i]] += v[i];
    }
    cout << (*max_element(v2.begin(), v2.end()) == v2[0] ? "YES\n" : "NO\n");
    return 0;
}
