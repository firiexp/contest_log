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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int y, m, d;
        scanf("%d %d %d", &y, &m, &d);
        int ans = 0;
        while(y != 1000 || m != 1 || d != 1){
            d++;
            if(y%3 && m%2 == 0){
                if(d > 19) d = 1, m++;
            }else {
                if(d > 20) d = 1, m++;
            }
            if(m > 10) m = 1, y++;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
