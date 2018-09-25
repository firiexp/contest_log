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
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }
    int k = 0;
    string s;
    for (auto &&x : m) if(k < x.second) {s = x.first; k = x.second;}

    cout << s << "\n";
    return 0;
}
