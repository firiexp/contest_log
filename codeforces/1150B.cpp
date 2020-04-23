#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<vector<int>> g(n+10, vector<int>(n+10, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i+1][j+1] = s[i][j] == '.';
        }
    }
    int valid = true;
    int dy[] = {1, 1, 1, 2}, dx[] = {-1, 0, 1, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!g[i+1][j+1]) continue;
            g[i+1][j+1] = 0;
            for (int k = 0; k < 4; ++k) {
                if(!g[i+1+dy[k]][j+1+dx[k]]) {
                    valid = false;
                    i = n, j = n;
                    break;
                }else g[i+1+dy[k]][j+1+dx[k]] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(g[i+1][j+1]) valid = false;
        }
    }
    puts(valid ? "YES" : "NO");
    return 0;
}