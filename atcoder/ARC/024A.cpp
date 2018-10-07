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
    int l, r, ans = 0;
    cin >> l >> r;
    map<int, int> m;
    for (int i = 0; i < l ;++i) {
        int k;
        cin >> k;
        m[k]++;
    }
    for (int i = 0; i < r; ++i) {
        int k;
        cin >> k;
        if(m[k])ans++, m[k]--;
    }
    cout << ans << "\n";
    return 0;
}
