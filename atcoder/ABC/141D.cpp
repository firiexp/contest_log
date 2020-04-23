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
    int n, m;
    cin >> n >> m;
    priority_queue<int> Q;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        Q.emplace(x);
    }
    for (int i = 0; i < m; ++i) {
        int x = Q.top(); Q.pop();
        Q.emplace(x/2);
    }
    ll ans = 0;
    while(!Q.empty()) {
        ans += Q.top(); Q.pop();
    }
    cout << ans << "\n";
    return 0;
}