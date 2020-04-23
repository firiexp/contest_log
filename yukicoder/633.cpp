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
    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) {
        int x;
        cin >> x;
        v[i+1] = v[i]+x;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int b, c;
        cin >> b >> c;
        if(b) ans += b*v[i];
        if(c) ans -= c*v[i];
    }
    cout << ans << "\n";
    return 0;
}
