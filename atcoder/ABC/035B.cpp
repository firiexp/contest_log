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
    int t;
    cin >> s >> t;
    int x = 0, y = 0, q = 0;
    for (auto &&p : s) {
        if(p == 'L') x++;
        if(p == 'R') x--;
        if(p == 'U') y++;
        if(p == 'D') y--;
        if(p == '?') q++;
    }
    if(t == 1){
        cout << abs(x)+abs(y)+q << "\n";
    }else {
        cout << max(abs(x)+abs(y)-q, (abs(abs(x)+abs(y)-q))%2) << "\n";
    }
    return 0;
}
