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
    int h, n;
    cin >> h >> n;
    vector<ll> ans(h+1, INF<ll>);
    ans.back() = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = h; j > 0; --j) {
            ans[max(j-a, 0)] = min(ans[max(j-a, 0)], ans[j]+b);
        }
    }
    cout << ans[0] << "\n";
    return 0;
}