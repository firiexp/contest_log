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
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, p, q;
        scanf("%d:%d %d:%d", &a, &b, &p, &q);
        int aa = a*60+b, bb = p*60+q;
        if(aa > bb) bb += 1440;
        ans += bb-aa;
    }
    cout << ans << "\n";

    return 0;
}
