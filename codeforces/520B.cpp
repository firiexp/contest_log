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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while(m != n){
        while(m < n) m++, ans++;
        if(m == n) break;
        if(m%2) m++, ans++;
        m /= 2; ans++;
    }
    cout << ans << "\n";
    return 0;
}
