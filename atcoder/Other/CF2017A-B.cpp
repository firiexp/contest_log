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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(i*m + n*j - 2*i*j == k) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
