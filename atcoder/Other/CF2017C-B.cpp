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
    int n, ans = 1, ans2 = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(!(k&1)) ans *= 2;
        ans2 *= 3;
    }
    cout << ans2-ans << "\n";
    return 0;
}
