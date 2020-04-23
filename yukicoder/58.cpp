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
    int n, k;
    cin >> n >> k;
    vector<array<long double, 61>> u(n+1), v(n+1);
    u[0][0] = 1; v[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 61; ++j) {
            for (int l = 1; l <= 6; ++l) {
                if(j+l >= 61) break;
                u[i+1][j+l] += u[i][j]/6;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 61; ++j) {
            for (int l = (i < k ? 4 : 1); l <= 6; ++l) {
                if(j+l >= 61) break;
                v[i+1][j+l] += v[i][j]/ (i < k ? 3 : 6);
            }
        }
    }
    long double ans = 0;
    for (int i = 0; i < 61; ++i) {
        for (int j = i+1; j < 61; ++j) {
            ans += u[n][i]*v[n][j];
        }
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
