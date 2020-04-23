#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;
using P = pair<int, int>;
int main() {
    int n, m;
    cin >> n >> m;
    vector<P> v1, v2;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v1.emplace_back(x, y);
    }
    for (int j = 0; j < m; ++j) {
        int x, y;
        cin >> x >> y;
        v2.emplace_back(x, y);
    }
    for (auto &&v : v1) {
        int k = INF, z = 0;
        int x = v.first, y = v.second;
        for (int i = 0; i < m; ++i) {
            int x1 = v2[i].first, y1 = v2[i].second;
            if(abs(x1-x) + abs(y1-y) < k) z = i+1, k = abs(x1-x) + abs(y1-y);
        }
        cout << z << "\n";
    }

    return 0;
}
