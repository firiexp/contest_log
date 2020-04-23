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
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        v[a-1][l]++;
        v[b-1][l]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &&j : v[i]) {
            if(j.first != 1270) ans += v[i][j.first]*v[i][2540-j.first];
            else ans += (v[i][j.first]-1)*v[i][j.first];
        }
    }
    cout << ans/2 << "\n";
    return 0;
}
