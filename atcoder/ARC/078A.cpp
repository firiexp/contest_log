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
    vector<ll> v;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
        v.emplace_back(sum);
    }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < n-1; ++i) {
        ans = min(ans, abs(sum-2*v[i]));
    }
    cout << ans << "\n";
    return 0;
}
