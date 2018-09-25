#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
using P = pair<int, int>;

static const int INF = 10000000;




int main() {
    vector<int> dp(100000, INF);
    vector<P> v(100000, {INF, INF});
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, -b);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), -v[i].second) = -v[i].second;
    }
    cout << (lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << "\n";
}
