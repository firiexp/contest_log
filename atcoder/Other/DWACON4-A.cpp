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
    if(s[0] == s[2] && s[1] == s[3]) cout << "Yes" << "\n";
    else cout << "No\n";
    return 0;
}
