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
    string ans = s.front() + to_string(s.length()-2) + s.back();
    cout << ans << "\n";
    return 0;
}
