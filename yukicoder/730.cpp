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
    map<char, int> v;
    string s;
    cin >> s;
    for (auto &&a : s) {
        v[a]++;
    }
    for (auto &&a : v) {
        if(a.second > 1) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}
