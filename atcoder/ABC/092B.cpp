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
    int n, d, x;
    cin >> n >> d >> x;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        x += (d-1)/k+1;
    }
    cout << x << "\n";
    return 0;
}
