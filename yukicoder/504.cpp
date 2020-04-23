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
    int k;
    cin >> k;
    int ans = 1;
    cout << ans << "\n";
    for (int i = 0; i < n-1; ++i) {
        int x;
        scanf("%d", &x);
        if(x > k) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
