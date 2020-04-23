#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    if(b <= a+2){
        cout << k+1 << "\n";
        return 0;
    }
    ll ans = 0;
    ans += min(k, a-1);
    k -= ans;
    ans += (b-a)*(k/2);
    cout << ans+k%2+1 << "\n";
    return 0;
}
