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
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &&c : s) {
        m[c]++;
    }
    for (auto &&item : m) {
        if(item.second > 1){
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}
