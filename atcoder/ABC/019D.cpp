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
    int n;
    cin >> n;
    ll k = 0, l = 0;
    for (int i = 1; i < n; ++i) {
        cout << "? 1 " << i+1 << endl;
        ll x;
        cin >> x;
        if(x > k){
            k = x, l = i;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(i == l) continue;
        cout << "? " << l+1 << " " << i+1 << endl;
        ll x;
        cin >> x;
        ans = max(ans, x);
    }
    cout << "! " << ans << endl;
    return 0;
}
