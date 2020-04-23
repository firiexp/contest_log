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
    ll x, y;
    cin >> x >> y;
    auto f = [&](ll x, ll y){
        if(x > y) swap(x, y);
        ll ans = 0;
        if(y >= 0){
            ans += y;
            x -= y; y -= y;
        }
        return (ans-(x+y))*2;
    };
    cout << min({f(x, y), f(x+1, y+1)+1, f(x-1, y)+1, f(x, y-1)+1}) << "\n";
    return 0;
}