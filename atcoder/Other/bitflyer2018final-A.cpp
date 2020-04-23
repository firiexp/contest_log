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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    for (int i = 0; i < n - 1; ++i) {
        int q;
        cin >> q;
        p = __gcd(p, q);
    }
    int ans = 0;
    while (!(p%10)){
        ans++;
        p/=10;
    }
    cout << ans << "\n";
    return 0;
}
