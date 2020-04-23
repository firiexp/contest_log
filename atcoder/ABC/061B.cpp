#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a]++; v[b]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i+1] << "\n";
    }
    return 0;
}
