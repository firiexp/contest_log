#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = -INF<int>;
    for (int i = 0; i < n; ++i) {
        int ma = -INF<int>, mb = -1;
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            int p = 0;
            for (int k = min(i, j)+1; k <= max(i, j); k += 2) {
                p += v[k];
            }
            if(p > ma){
                ma = p;
                mb = j;
            }
        }
        int p = 0;
        if(mb != -1) for (int k = min(i, mb); k <= max(i, mb); k += 2) {
            p += v[k];
        }
        ans = max(ans, p);
    }
    cout << ans << "\n";
    return 0;
}
