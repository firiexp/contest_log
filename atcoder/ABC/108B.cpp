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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2-x1, dy = y2-y1;
    cout << x2-dy << " " << y2+dx << " " << x2-dy-dx << " " << y2+dx-dy << "\n";
    return 0;
}
