#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    unsigned n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    x = x - accumulate(v.begin(), v.end(), 0);
    int ans = n;
    ans += (x / v[0]);
    cout << ans << "\n";
    return 0;
}
