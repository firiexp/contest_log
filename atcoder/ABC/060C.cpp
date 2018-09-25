#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, t, ans = 0;
    cin >> n >> t;
    vector<int> v;
    v.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v.emplace_back(a);
        ans += min(v[i+1]-v[i], t);
    }
    ans += t;
    cout << ans << "\n";
    return 0;
}
