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
    int w, a, b;
    cin >> w >> a >> b;
    cout << max(abs(a-b)-w , 0);
    return 0;
}
