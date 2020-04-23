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
    vector<map<int, int>> v(3);
    vector<vector<int>> u(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[0][a]++; v[1][b]++; v[2][c]++;
        u[i].emplace_back(a);
        u[i].emplace_back(b);
        u[i].emplace_back(c);
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < 3; ++j) {
            if(v[j][u[i][j]] == 1) ans += u[i][j];
        }
        cout << ans << "\n";
    }
    return 0;
}
