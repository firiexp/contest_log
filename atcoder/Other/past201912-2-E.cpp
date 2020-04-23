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

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, q;
    cin >> n >> q;
    auto v = make_v(n, n, 0);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        if(x == 1){
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            v[a][b] = 1;
        }else if(x == 2){
            int a;
            scanf("%d", &a);
            a--;
            for (int j = 0; j < n; ++j) {
                if(v[j][a]) v[a][j] = 1;
            }
        }else {
            int a;
            scanf("%d", &a);
            a--;
            vector<int> vv;
            for (int j = 0; j < n; ++j) {
                if(!v[a][j] || a == j) continue;
                vv.emplace_back(j);
            }
            for (auto &&j : vv) {
                for (int k = 0; k < n; ++k) {
                    if(a == k) continue;
                    if(v[j][k] == 1) {
                        v[a][k] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (v[i][j] ? 'Y' : 'N');
        }
        puts("");
    }
    return 0;
}