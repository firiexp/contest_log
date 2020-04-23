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
    int n, m;
    cin >> n >> m;
    vector<int> v(m, 0);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v[k-1]++;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            ans += v[i]*v[j];
        }
    }
    cout << ans << "\n";
    return 0;
}
