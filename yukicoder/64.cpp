#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = 0;
    if(n%3 == 2){
        ans = a ^ b;
    }else if(n%3 == 0){
        ans = a;
    }else {
        ans = b;
    }
    cout << ans << "\n";

    return 0;
}
