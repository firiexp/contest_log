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
    int n;
    cin >> n;
    vector<int> ls, rs;
    ll ans = (ll)n*n;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        int prv = 0, l = INF<int>, r = -INF<int>, ok = 1;
        for (int j = 0; j < x; ++j) {
            int p;
            scanf("%d", &p);
            if(j != 0 && prv < p) ok = 0;
            prv = p;
            l = min(l, p);
            r = max(r, p);
        }
        if(ok){
            rs.emplace_back(l);
            ls.emplace_back(r);
        }
    }
    sort(ls.begin(),ls.end());
    for (int i = 0; i < ls.size(); ++i) {
        ans -= lower_bound(ls.begin(),ls.end(), rs[i]+1) - ls.begin();
    }
    cout << ans << "\n";
    return 0;
}