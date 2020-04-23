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
    vector<string> v;
    for (int i = 0; i < 16; ++i) {
        string s;
        cin >> s;
        v.emplace_back(s);
    }
    for (int j = 15; j >= 0; --j) {
        cout << v[j];
        if(j%4) cout << " ";
        else cout << "\n";
    }
    return 0;
}
