#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s.substr(0, 3) == "yah" && s[3] == s[4]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}
