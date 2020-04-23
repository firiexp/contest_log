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
    int n, x, ans = 0;
    string s;
    cin >> n >> x >> s;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if(s[i]-'0') ans += min(t, x);
        else ans += t;
    }
    cout << ans << "\n";
    return 0;
}
