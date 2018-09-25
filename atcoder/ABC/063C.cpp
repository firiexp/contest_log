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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        if(s[i] != s[i-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
