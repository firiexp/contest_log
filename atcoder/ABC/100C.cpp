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
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        while (a % 2 == 0){
            a /= 2;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
