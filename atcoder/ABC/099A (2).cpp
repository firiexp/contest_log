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
    int n, k;
    cin >> n >> k;
    int ans = (n - 1 + k - 1 - 1) / (k - 1);
    cout << ans << "\n";
    return 0;
}
