#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    set<ll> k;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        k.insert(sum);
    }
    int m;
    cin >> m;
    ll sum1 = sum;
    sum = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        if(k.count(sum)) ans++;
    }
    if(ans == 0 || sum1 != sum) ans = -1;
    cout << ans << "\n";
    return 0;
}
