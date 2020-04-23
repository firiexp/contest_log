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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = max(0, v.front()-m)+max(0, t-v.back()-m);
    for (int i = 0; i < n-1; ++i) {
        ans += max(0, v[i+1]-v[i]-2*m);
    }
    cout << ans << "\n";
    return 0;
}