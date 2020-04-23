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

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    int p = 0;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(i);
        v[b].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if(!v[i].empty()){
            printf("%d\n", int(v[i].size()));
            for (int j = 1; j <= v[i].size(); ++j) {
                printf("%d %d\n", i, v[i][j-1]);
            }
        }else {
            printf("1\n");
            printf("%d %d\n", p+100000000, p+100000000);
            p++;
        }
    }
    return 0;
}
