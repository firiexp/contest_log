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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll x, y;
    cin >> x >> y;
    ll ans = INF<ll>;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(x-2*i*x <= y-2*j*y){
                ans = min(ans, y-2*j*y-x+2*i*x+i+j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
