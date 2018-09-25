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
    int x , y;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A') {
            x = i;
            break;
        }
    }

    for (int i = s.length()-1; i > 0; --i) {
        if(s[i] == 'Z') {
            y = i;
            break;
        }
    }
    cout << y-x+1 << "\n";
    return 0;
}
