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
    int n;
    cin >> n;
    int k, p = 1, ans = 0;
    cin >> k;
    for (int i = 0; i < n-1; ++i) {
        int x;
        cin >> x;
        if(x == k) p++;
        else {ans += p/2; p = 1;}
        k = x;
    }
    ans += p/2;
    cout << ans << "\n";
    return 0;
}
