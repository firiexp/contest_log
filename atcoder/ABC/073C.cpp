#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        m[a]^=1;
    }
    int ans = 0;
    for (auto &&i : m) {
        ans += i.second;
    }
    cout << ans << "\n";
    return 0;
}
