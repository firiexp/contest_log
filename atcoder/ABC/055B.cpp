#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;


int main() {
    ll n, ans = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        ans = (ans * i) % INF;
    }
    cout << ans << "\n";
    return 0;
}
