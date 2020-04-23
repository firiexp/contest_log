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
    vector<vector<int>> v;
    vector<int> x(m), z(m);
    map<int, int> map1;
    for (int i = 0; i < m; ++i) {
        int p, y;
        scanf("%d %d", &p, &y);
        v.emplace_back(vector<int>{p, y, i});
        z[i] = p;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; ++i) {
        map1[v[i][0]]++;
        x[v[i][2]] = map1[v[i][0]];
    }
    for (int i = 0; i < m; ++i) {
        printf("%06d%06d\n", z[i], x[i]);
    }
    return 0;
}
