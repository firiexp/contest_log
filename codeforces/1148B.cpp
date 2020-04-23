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
    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;
    vector<int> v(n), u(m);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    if(n <= k){
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= min(n-1, k); ++i) {
        int x = lower_bound(u.begin(),u.end(), v[i]+a) - u.begin();
        x += k-i;
        if(x >= m){
            puts("-1");
            return 0;
        }
        ans = max(ans, u[x]+b);
    }
    cout << ans << "\n";
    return 0;
}