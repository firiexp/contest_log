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
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        string k = to_string(i);
        if(k[0] == k[4] && k[1] == k[3]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
