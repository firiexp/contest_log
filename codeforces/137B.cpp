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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    array<int, 5001> cnt{};
    for (int i = 0; i < n; ++i) {
        cnt[v[i]-1]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!cnt[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}