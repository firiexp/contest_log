#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;


vector<vector<int>> v;

int sum(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    else return v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1];
}

int main() {
    int n, k;
    cin >> n >> k;
    v = vector<vector<int>>(2*k+1, vector<int>(2*k+1, 0));
    for (int i = 0; i < n; ++i) {
        int a, b;
        char c;
        scanf("%d %d %c", &a, &b, &c);
        if(c == 'B') b += k;
        v[a%(2*k)+1][b%(2*k)+1]++;
    }
    for (int i = 0; i <= 2*k; ++i) {
        for (int j = 1; j <= 2*k; ++j) {
            v[i][j] += v[i][j-1];
        }
    }
    for (int i = 0; i <= 2*k; ++i) {
        for (int j = 1; j <= 2*k; ++j) {
            v[j][i] += v[j-1][i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            int res = sum(i, j, i+k-1, j+k-1)
                    + sum(i+k, j+k, 2*k, 2*k)
                    + sum(1, 1, i-1, j-1)
                    + sum(i+k, 1, 2*k, j-1)
                    + sum(1, j+k, i-1, 2*k);
            ans = max({ans, res, n-res});
        }
    }
    cout << ans << "\n";
    return 0;
}
