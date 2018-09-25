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
    string s;
    cin >> s;
    s = "x" + s;
    for (int i = 1; i < s.length(); ++i) {
        if(s[i] == 'h' && s[i-1] != 'c'){
            cout << "NO\n";
            return 0;
        }
        if(s[i] == 'c' && s[i+1] != 'h'){
            cout << "NO\n";
            return 0;
        }
        if(s[i] == 'c' || s[i] == 'h' || s[i] == 'o' || s[i] == 'k' || s[i] == 'u');
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
