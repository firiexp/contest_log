#include <iostream>
#include <deque>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int A[12][12];
    int n, m, x, y, ma = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = 0;
        }
        A[i][i] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        A[x-1][y-1] = A[y-1][x-1] = 1;
    }
    for (int i = 0; i < (1 << n); ++i) {
        int s = 0;
        bool flag = true;
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) {s++; v.emplace_back(j);}
        }
        for (auto &a : v) {
            for (auto &b : v) {
                if(!A[a][b]){
                    flag = false;
                }
            }
        }
        if (flag) ma = max(ma, s);
    }
    cout << ma << "\n";
    return 0;
}
