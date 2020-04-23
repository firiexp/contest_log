#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int ans1 = 0;
        set<int> s;
        for (int j = 0; j < n; ++j) {
            if(i == v[j]) ans1++;
            else if(abs(i-v[j]) <= k) s.emplace(abs(i-v[j]));
        }
        ans = max(ans, ans1+(int)s.size());
    }
    cout << ans << "\n";
    return 0;
}