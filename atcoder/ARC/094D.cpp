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
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        ll a, b;
        cin >> a >> b;
        ll c = 0, notc = INF<int>;
        if(a > b) swap(a, b);
        if(llabs(b-a) <= 1) {
            cout << 2*a-2 << "\n";
            continue;
        }
        while(notc - c > 1){
            ll mid = (c+notc)/2;
            if(mid*mid < a*b) c = mid;
            else notc = mid;
        }
        if(c*(c+1) < a*b) cout << 2*c-1 << "\n";
        else cout << 2*c-2 << "\n";
    }
    return 0;
}
