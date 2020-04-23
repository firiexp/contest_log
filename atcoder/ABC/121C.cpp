#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    int x = 0;
    int cnt = 0;
    while(x < m){
        ans += (ll)v[cnt].first*min(v[cnt].second, m-x);
        x += min(v[cnt].second, m-x);
        cnt++;
    }
    cout << ans << "\n";
    return 0;
}
