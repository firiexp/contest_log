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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for (ll i = 9; i <= b; i = i*10+9) {
            ans += a;
        }
        cout << ans << "\n";
    }
    return 0;
}