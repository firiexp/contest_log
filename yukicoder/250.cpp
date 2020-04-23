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
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll d, x, t;
        cin >> d >> x >> t;
        ll k = 1, cnt = 1;
        if(k > t) {
            puts("ZETUBOU");
            continue;
        }
        while(cnt < d){
            k = k*(cnt+x);
            k = k/cnt;
            if(k > t) {
                cnt = -1;
                break;
            }
            cnt++;
        }
        puts(cnt < d ? "ZETUBOU" : "AC");
    }
    return 0;
}
