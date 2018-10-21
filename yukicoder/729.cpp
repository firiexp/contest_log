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
    int a, b;
    cin >> s >> a >> b;
    swap(s[a], s[b]);
    cout << s << "\n";
    return 0;
}
