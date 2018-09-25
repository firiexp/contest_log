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
    int k, t;
    cin >> k >> t;
    int m = 0;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        m = max(m, a);
    }
    cout << max(0, m-(k-m)-1) << "\n";
    return 0;
}
