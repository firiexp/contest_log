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
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        int ok = 0;
        for (int x = 0; x <= k; ++x) {
            int y = k-x;
            if((a+c-1)/c <= x && (b+d-1)/d <= y){
                printf("%d %d\n", x, y);
                ok = 1;
                break;
            }
        }
        if(!ok) puts("-1");
    }
    return 0;
}