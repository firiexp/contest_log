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
    ll x, y, h;
    cin >> x >> y >> h;
    int ans = 0;
    auto f = [&](ll x, ll y, ll h, auto &&f) -> int {
        int ans = 0;
        if(x*1000 > h) ans = max(ans, f(x, y*2, h*4, f)+1);
        if(y*1000 > h) ans = max(ans, f(x*2, y, h*4, f)+1);
        return ans;
    };
    cout << f(x, y, h, f) << "\n";
    return 0;
}