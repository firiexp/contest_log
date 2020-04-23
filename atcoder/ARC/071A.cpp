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
    map<char, int> v;
    for (int i = 0; i < n; ++i) {
        map<char, int> v2;
        string s;
        cin >> s;
        for (auto &&a : s) {
            v2[a]++;
        }
        if(i == 0) v = v2;
        for (auto &&a : v) {
            a.second = min(v2[a.first], a.second);
        }
    }
    string k;
    for (auto &&a : v) {
        k += string(static_cast<unsigned int>(a.second), a.first);
    }
    sort(k.begin(), k.end());
    cout << k << "\n";
    return 0;
}
