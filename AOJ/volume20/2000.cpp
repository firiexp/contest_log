#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        array<array<int, 21>, 21> v{};
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            v[b][a]++;
        }
        v[10][10] = 0;
        int m;
        cin >> m;
        string s = "NESW";
        int dy[] {1, 0, -1, 0}, dx[] {0, 1, 0, -1};
        int y = 10, x = 10;
        for (int i = 0; i < m; ++i) {
            char c; int w;
            cin >> c >> w;
            for (int cc = 0; cc < 4; ++cc) {
                if(s[cc] == c){
                    for (int j = 0; j < w; ++j) {
                        y += dy[cc], x += dx[cc];
                        v[y][x] = 0;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= 20; ++i) {
            for (int j = 0; j <= 20; ++j) {
                if(v[i][j]) ans++;
            }
        }
        puts(ans ? "No" : "Yes");
    }
    return 0;
}
