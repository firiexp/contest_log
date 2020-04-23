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
    string s, t = "aiueo", ans;
    map<int, int> x;
    for (auto &&a : t) x[a]++;
    cin >> s;
    for (auto &&a : s) if(!x[a]) ans += a;
    cout << ans << "\n";
    return 0;
}
