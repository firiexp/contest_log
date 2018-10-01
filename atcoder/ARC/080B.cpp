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
template <class T, size_t D> struct _Vec {
    using type = vector<typename _Vec<T, D-1>::type>;
};
template <class T> struct _Vec<T, 1> {
    using type = vector<T>;
};
template<class T, size_t D> using Vec = typename _Vec<T, D>::type;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            v.emplace_back(i+1);
        }
    }
    Vec<int, 2> m = make_v(h, w, 0);
    for (int i = 0; i < h; ++i) {
        if((i&1) == 0) for (int j = 0; j < w; ++j) {
            m[i][j] = v[w*i+j];
        }
        else for (int j = w-1; j >= 0; --j) {
             m[i][j] = v[w*i+w-j-1];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) printf(" ");
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
