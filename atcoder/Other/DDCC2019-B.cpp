#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long double u = i, v = j;
            int f = true;
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if(fabs((u+k)/n -0.5)+fabs((v+l)/n -0.5) > 0.5) {
                        f = false;
                    }
                }
            }
            ans += (f ? 1 : 0);
        }
    }
    cout << ans << "\n";
    return 0;
}
