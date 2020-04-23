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
    int n, q;
    cin >> n >> q;
    set<int> S;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(S.count(x)) S.erase(x);
        else S.insert(x);
    }
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        int cnt = 0, ans = 0;
        auto lb = S.lower_bound(l), ub = S.upper_bound(r);
        for (auto j = lb; j != S.end() && *j <= r; j = S.erase(j)) {
            cnt ^= 1;
            ans ^= *j;
        }
        if(cnt) {
            if(S.count(x)) S.erase(x);
            else S.insert(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}