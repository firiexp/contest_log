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
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.emplace_back(s);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= 0; --j) {
            cout << v[j][i];
        }
        cout << "\n";
    }
    return 0;
}
