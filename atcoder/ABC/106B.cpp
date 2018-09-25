#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    if (n >= 105) ans++;
    if (n >= 135) ans++;
    if (n >= 165) ans++;
    if (n >= 189) ans++;
    if (n >= 195) ans++;
    cout << ans << "\n";
    return 0;
}
