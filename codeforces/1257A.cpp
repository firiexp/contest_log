#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        int ans = -INF<int>;
        a--; b--;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(abs(i-a)+abs(j-b) <= x) {
                    ans = max(ans, abs(i-j));
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}