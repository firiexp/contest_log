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
    int a, b, c, ans;
    cin >> a >> b >> c;
    if(a == b) ans = c;
    else if(b == c) ans = a;
    else ans = b;
    cout << ans << "\n";
    return 0;
}
