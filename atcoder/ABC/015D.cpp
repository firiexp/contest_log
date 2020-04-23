#include <iostream>
#include <array>
#include <vector>

using ll = long long;
using namespace std;
int a[51][10001]{};

int main() {
    int w, n, k, ans = 0;
    cin >> w >> n >> k;

    fill_n(&a[0][0], 510051, 0);
    for (int i = 1; i <= n; ++i) {
        int x , y;
        cin >> x >> y;
        for (int j = min(k, i); j > 1; --j) {
            for (int l = w; l > x; --l) {
                if(a[j-1][l-x])  {
                    a[j][l] = max(a[j-1][l-x]+y, a[j][l]);
                    ans = max(a[j][l], ans);
                }
            }
        }
        if(a[1][x] < y && x <= w) {
            a[1][x] = y;
            ans = max(y, ans);
        }
    }
    cout << ans << "\n";
    return 0;
}
