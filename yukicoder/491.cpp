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
    ll n;
    cin >> n;
    n /= 1000000001;
    ll ans = 0;
    for (int i = 1; i <= 99999; ++i) {
        string s = to_string(i), t = s;
        reverse(t.begin(),t.end());
        if(i <= 9999) {
            ll u = stoll(s+t);
            if(u <= n) ans++;
        }
        s.pop_back();
        ll u = stoll(s+t);
        if(u <= n) ans++;
    }
    cout << ans << "\n";
    return 0;
}