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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    int p = (lower_bound(v.begin(), v.end(), x)-v.begin());
    cout << min(p, m-p) << "\n";
    return 0;
}
