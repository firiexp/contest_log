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
    auto v = make_v(2, 2*n, 0);
    for (int i = 0; i < 2*n; ++i) {
        v[0][i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int now = i%2, nxt = (i+1)%2;
        int k;
        cin >> k;
        if(k == 0){
            for (int j = 0; j < n; ++j) {
                v[nxt][2*j] = v[now][j];
                v[nxt][2*j+1] = v[now][j+n];
            }
        }else {
            for (int j = 0; j < 2 * n; ++j) {
                v[nxt][(j-k+2*n)%(2*n)] = v[now][j];
            }
        }
    }
    for (int i = 0; i < 2*n; ++i) {
        cout << v[m%2][i]+1 << "\n";
    }
    return 0;
}
