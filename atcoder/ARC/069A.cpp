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
    ll n, m;
    cin >> n >> m;
    ll ans = min(n, m/2);
    n-=ans; m-=ans*2;
    ans += m/4;
    cout << ans << "\n";
    return 0;
}
