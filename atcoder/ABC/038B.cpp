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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c || b == c || a == d || b == d) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}
