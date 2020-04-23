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
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> vs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &vs[i].first, &vs[i].second);
    }
    sort(vs.begin(),vs.end());
    for (int i = 1; i < n; ++i) {
        vs.emplace_back(vs[i-1].second, vs[i].first);
    }
    vs.emplace_back(vs.back().second, vs.back().second + h + 1);
    sort(vs.begin(),vs.end());
    int m = 2*n - 1;
    ll ans = h, cost = 0, val = 0;
    int l = 0, r = 0;
    while(r < m){
        val += vs[r].second - vs[r].first;
        if(r&1) cost += vs[r].second - vs[r].first;
        r++;
        while(cost >= h){
            val -= vs[l].second - vs[l].first;
            if(l&1) cost -= vs[l].second - vs[l].first;
            l++;
        }
        ans = max(ans, val + h - cost);
    }
    cout << ans << "\n";
    return 0;
}