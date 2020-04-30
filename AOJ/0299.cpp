#include <iostream>
#include <algorithm>
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
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> val(m);
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        val[i] = (x+n-p)%n;
    }
    sort(val.begin(),val.end());
    int ans = min(val.back(), n-val.front());
    for (int i = 0; i+1 < m; ++i) {
        int l = val[i], r = n-val[i+1];
        ans = min(ans, l+r+min(l, r));
    }
    cout << ans*100 << "\n";
    return 0;
}