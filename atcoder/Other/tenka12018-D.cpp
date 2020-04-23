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
    int n;
    cin >> n;
    ll i = 0;
    while(i*(i+1)/2 < n)i++;
    if(n != i*(i+1)/2){
        puts("No");
        return 0;
    }else {
        puts("Yes");
        cout << i+1 << "\n";
    }
    auto v = make_v(i+1, i, 0);
    int p = 1, q = 1;
    for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i-j; ++k) {
            v[j][k+j] = p;
            v[k+j+1][j] = p;
            p++;
        }
    }
    for (int j = 0; j < i+1; ++j) {
        printf("%d", i);
        for (int k = 0; k < i; ++k) {
            printf(" ");
            printf("%d", v[j][k]);
        }
        printf("\n");
    }
    return 0;
}
