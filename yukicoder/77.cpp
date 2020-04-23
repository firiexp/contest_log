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
    int n;
    cin >> n;
    array<int, 501> v{};
    int ans = INF<int>, s = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        s += v[i];
    }
    s--;
    for (int i = 1; i <= 300 && s >= 0; i += 2, s -= i) {
        int t = 0;
        for (int j = 0; j < 300; ++j) {
            int val = max(min(j+1, i-j), 0);
            if(v[j] >= val) t += v[j] - val;
        }
        ans = min(ans, t);
    }
    cout << ans << "\n";
    return 0;
}
