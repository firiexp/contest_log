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
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(k%6 == 0) ans += 3;
        if(k%6 == 2) ans += 1;
        if(k%6 == 4) ans += 1;
        if(k%6 == 5) ans += 2;
    }
    cout << ans << "\n";
    return 0;
}
