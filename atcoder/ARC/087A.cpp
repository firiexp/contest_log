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
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v[a]++;
    }
    int ans = 0;
    for (auto &&x : v) {
        ans += (x.second >= x.first ? (x.second - x.first): x.second);
    }
    cout << ans << "\n";
    return 0;
}
