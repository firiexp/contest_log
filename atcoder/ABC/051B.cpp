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
    int k, s, ans = 0;
    cin >> k >> s;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            if(0 <= s-i-j && s-i-j <= k){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
