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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int e = c;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            e += v[j]*x;
        }
        if(e > 0) ans++;
    }
    cout << ans << "\n";
    return 0;
}
