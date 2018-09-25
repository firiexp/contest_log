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
    u32 h, w;
    cin >> h >> w;
    vector<vector<char> > v(h+2, vector<char> (w+2, '#'));
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; ++j) {
            v[i][j] = s[j-1];
        }
    }
    for (auto &&vv : v) {
        for (auto &&c : vv) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}
