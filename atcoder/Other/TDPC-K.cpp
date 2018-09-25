#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
using P = pair<int, int>;
static const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vector<P> v(200000, {INF, INF});
    vector<int> dp(200000, INF);
    for (int i = 0; i < n; ++i) {
        int x, r;
        scanf("%d %d", &x, &r);
        v.emplace_back(r-x, -x-r);
    }
    sort(v.begin(), v.end());
    for (auto &a : v) {
        int q = a.second;
        *lower_bound(dp.begin(), dp.end(), -q) = -q;
    }
    cout << lower_bound(dp.begin(), dp.end(), INF)-dp.begin() << "\n";
    return 0;
}
