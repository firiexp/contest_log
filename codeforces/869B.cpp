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
    ll a, b;
    cin >> a >> b;
    if(b-a > 10){
        puts("0");
    }else {
        ll ans = 1;
        for (ll i = a+1; i <= b; ++i) {
            ans = (ans%10)*(i%10)%10;
        }
        cout << ans << "\n";
    }
    return 0;
}