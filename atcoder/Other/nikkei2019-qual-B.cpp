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
    int n;
    cin >> n;
    string s, t, u;
    cin >> s >> t >> u;
    vector<map<int, int>> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        v[i][s[i]]++, v[i][t[i]]++, v[i][u[i]]++;
        int p = 0;
        for (auto &&j : v[i]) {
            p = max(p, j.second);
        }
        ans += 3-p;
    }
    cout << ans << "\n";
    return 0;
}
