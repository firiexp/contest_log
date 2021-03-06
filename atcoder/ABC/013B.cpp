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
    int a, b;
    cin >> a >> b;
    int x = min(b+10-a, a+10-b);
    cout << min(abs(b-a), x) << "\n";
    return 0;
}
