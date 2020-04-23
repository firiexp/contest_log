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
    int n, xl, xr;
    cin >> n >> xl >> xr;
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v[i] = {a, b, c, d};
    }
    vector<int> ans(n);
    for (int x = xl; x <= xr; ++x) {
        int M = -INF<int>, c = -1;
        for (int i = 0; i < n; ++i) {
            if(v[i][0] <= x && x <= v[i][2]) {
                if(M < v[i][3]){
                    M = v[i][3]; c = i;
                }
            }
        }
        if(c != -1){
            ans[c] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
