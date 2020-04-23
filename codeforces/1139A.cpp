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
    ll ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if((s[i]-'0')%2 == 0) ans += i+1;
    }
    cout << ans << "\n";
    return 0;
}
