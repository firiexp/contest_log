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
    vector<int> v(9, 0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[min(a/400,8)]++;
    }
    for (int i = 0; i < 8; ++i) {
        if(v[i]) ans++;
    }
    cout << max(ans,1) << " " << ans+v[8] << "\n";
    return 0;
}
