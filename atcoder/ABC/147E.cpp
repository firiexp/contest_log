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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w;
    cin >> h >> w;
    auto A = make_v(h, w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x;
            cin >> x;
            A[i][j] -= x;
        }
    }
    auto v = make_v(h, w, vector<int>{});
    v[0][0].resize((h+w)*82);
    v[0][0][abs(A[0][0])]++;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < v[i][j].size(); ++k) {
                if(!v[i][j][k]) continue;
                if(i != h-1){
                    v[i+1][j].resize((h+w)*82);
                    v[i+1][j][abs(k-A[i+1][j])]++;
                    v[i+1][j][abs(k+A[i+1][j])]++;
                }
                if(j != w-1){
                    v[i][j+1].resize((h+w)*82);
                    v[i][j+1][abs(k-A[i][j+1])]++;
                    v[i][j+1][abs(k+A[i][j+1])]++;
                }
            }
            if(i != h-1 || j != w-1) v[i][j].clear();
        }
    }
    for (int i = 0; i < v.back().back().size(); ++i) {
        if(v.back().back()[i]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}