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
    int m, d;
    cin >> m >> d;
    cout << (m % d ? "NO" : "YES") << "\n";
    return 0;
}
