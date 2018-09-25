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
    int ans = 1, x;
    cin >> x;
    while(ans * (ans+1)/2 < x) ans++;
    cout << ans << "\n";
    return 0;
}
