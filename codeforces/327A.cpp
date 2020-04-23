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
    int ans1 = accumulate(v.begin(),v.end(), 0);
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        cnt[i+1] = cnt[i]+1-2*v[i];
    }
    int ans2 = -INF<int>, m = 0;
    for (int i = 1; i <= n; ++i) {
        ans2 = max(ans2, cnt[i]-m);
        m = min(m, cnt[i]);
    }
    cout << ans1 + ans2 << "\n";
    return 0;
}