#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    int a[2*n+1];
    a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i*2+1] >> a[i*2+2];
        ans += a[i*2+2]-a[i*2+1]+1;
        ans += (a[i*2+1]-a[i*2]-1)%x;
    }

    cout << ans << "\n";

    return 0;
}