#include <iostream>
#include <vector>
#include <deque>

using ll = long long;
using namespace std;

int main() {
    int n;
    int b = 0;
    int INF = 9999;
    cin >> n;
    int x[4], y[4];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        b += x[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            y[j] = (i & (1<<j)) ? 1 : 0;
        }
        int a = 0;
        for (int j = 0; j < n; ++j) {
            a += x[j] * y[j];
        }
        INF = min(INF, max(a, b-a));
    }
    cout << INF << "\n";
    return 0;
}
