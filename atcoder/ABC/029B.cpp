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
    int ans = 0;
    for (int i = 0; i < 12; ++i) {
        string s;
        cin >> s;
        ans += (count(s.begin(), s.end(), 'r')>0);
    }
    cout << ans << "\n";
    return 0;
}
