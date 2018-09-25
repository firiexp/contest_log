#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    string s, t = "yahoo";
    map<char, int> m;
    cin >> s;
    for (int i = 0; i < 5; ++i) {
        m[s[i]]++;
        m[t[i]]--;
    }
    for (auto &&i : m) {
        if(i.second != 0){
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}
