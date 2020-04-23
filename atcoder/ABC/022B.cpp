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
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        m[k]++;
    }
    int ans = 0;
    for (auto &&a : m) if(a.second) ans += a.second-1;
    cout << ans << "\n";
    return 0;
}
