#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans;
    if(a&b&c&1){
        ans = min({a*b, b*c, c*a});
    }else ans = 0;
    cout << ans << "\n";
    return 0;
}
