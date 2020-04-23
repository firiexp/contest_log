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
    int ans = 0;
    ll a = 0, b = 0;
    cin >> a >> b;
    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
