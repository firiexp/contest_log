#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 1;
    x -= y + 2*z;
    ans += x / (y + z);
    cout << ans << "\n";
    return 0;
}
