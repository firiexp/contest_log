#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.emplace_back(-t);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += -v[i] * (1 - (i % 2) * 2);
    }
    cout << ans << "\n";
    return 0;
}
