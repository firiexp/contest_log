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
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    if(n > m) swap(n, m);
    if((ll)n*m==1) ans = 1;
    else if (n == 1) ans = m-2;
    else ans = (ll)(n-2)*(m-2);
    cout << ans << "\n";
    return 0;
}
