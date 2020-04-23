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
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    ll n, k;
    cin >> n >> k;
    int m = n/k;
    if(n == 1){
        puts("Yes");
        cout << 1 << "\n";
        return 0;
    }else if(k == 1){
        puts("Yes");
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", i+1);
        }
        puts("");
    }else if(m%2 == 0){
        puts("Yes");
        auto v = make_v(m, k, 0);
        int cnt = 1;
        for (int i = 0; i < m; ++i) {
            if(i&1){
                for (int j = 0; j < k; ++j) {
                    v[i][j] = cnt++;
                }
            }else {
                for (int j = k-1; j >= 0; --j) {
                    v[i][j] = cnt++;
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                if(j) printf(" ");
                printf("%d", v[j][i]);
            }
            puts("");
        }
        return 0;
    }
    puts("No");
    return 0;
}