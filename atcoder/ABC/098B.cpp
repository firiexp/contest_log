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
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        string x = s.substr(0, i), y = s.substr(i, n-i+1);
        int k = 0;
        for (char j = 'a'; j <= 'z'; ++j) {
            if(x.find(j) != string::npos && y.find(j) != string::npos) k++;
        }
        ans = max(k, ans);
    }
    cout << ans << "\n";
    return 0;
}
