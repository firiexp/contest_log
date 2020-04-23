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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int x, y, n;
    while(cin >> x >> y >> n, x|y|n){
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if(i*(x+100)/100+j*(x+100)/100 == n){
                    ans = max(ans, i*(y+100)/100+j*(y+100)/100);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
