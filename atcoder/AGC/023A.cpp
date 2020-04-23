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
    int n;
    cin >> n;
    map<ll, ll> v;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        sum += k;
        v[sum]++;
    }
    ll ans = 0;
    for (auto &&x : v) if(x.second) ans += x.second * (x.second-1) / 2;
    ans += v[0];
    cout << ans << "\n";
    return 0;
}
