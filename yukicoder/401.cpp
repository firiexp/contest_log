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

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+2, vector<int>(n+2, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i+1][j+1] = 0;
        }
    }
    int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
    int a = 0, p = 1, q = 1, d = 0;
    for (int i = 1; i <= n*n; ++i) {
        v[p][q] = i;
        if(v[p+dy[d]][q+dx[d]] == 0){
            p += dy[d];
            q += dx[d];
        }else {
            d = (d+1)%4;
            p += dy[d];
            q += dx[d];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(j != 1) cout << " ";
            printf("%03d", v[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
