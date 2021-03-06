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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = v.back()-v.front();
    for (int i = 0; i+1 < n; ++i) {
        ans = min(ans, k-(v[i+1]-v[i]));
    }
    cout << ans << "\n";
    return 0;
}