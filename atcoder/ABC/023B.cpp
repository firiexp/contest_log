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
    string s;
    cin >> n >> s;
    if(n % 2 == 0) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int c = (103 - n/2 + i)%3 + 'a';
        if(c != s[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << n/2 << "\n";
    return 0;
}
