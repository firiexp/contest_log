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
    ll n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c; ll y;
        cin >> c >> y;
        if(c == '+'){
            x += y;
        }else {
            if(x < y) ans++;
            else  x -= y;
        }
    }
    cout << x << " " << ans << "\n";
    return 0;
}