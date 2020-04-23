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
    int q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        while(n){
            if(n%k != 0) ans += n%k, n -= n%k;
            else n /= k, ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}