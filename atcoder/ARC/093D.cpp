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
    int a, b;
    cin >> a >> b;
    int k = 64;
    auto v = make_v(k, k, 0);
    for (int i = k/2; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            v[i][j] = 1;
        }
    }
    int x = 0, y = 0;
    while(a-1){
        a--;
        v[y][x] ^= 1;
        x += 2;
        if(x == k) {
            y+=2;
            x=0;
        }
    }
    x = 0, y = k-1;
    while(b-1){
        b--;
        v[y][x] ^= 1;
        x += 2;
        if(x == k) {
            y-=2;
            x=0;
        }
    }
    printf("%d %d\n", k, k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            printf(v[i][j] ? "." : "#");
        }
        printf("\n");
    }
    return 0;
}
