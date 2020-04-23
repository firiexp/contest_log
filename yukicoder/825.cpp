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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INF<int>;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 1; k <= a+10*b; ++k) {
                int x = i+j*10-k;
                if(x < 0) continue;
                int p = (a-i)+(b-j)+x%10+x/10;
                if(p == c) {
                    ans = min(ans, k);
                }
            }
        }
    }
    if(ans == INF<int>) puts("Impossible");
    else cout << ans << "\n";
    return 0;
}