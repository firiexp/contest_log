#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
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
    ll ans = 0;
    auto v = make_v(h, w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    vector<array<int, 4>> li;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if(i == k && j == l) continue;
                    vector<int> tmp{i, j, k, l};
                    sort(tmp.begin(), tmp.end());
                    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
                    if(tmp.size() == 3) li.push_back({i, j, k, l});
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = i+1; j < h; ++j) {
            int cnt[3][3];
            for (auto & k : cnt) for (int & l : k) l = 0;

            for (int k = 0; k < w; ++k) {
                cnt[v[i][k]][v[j][k]]++;
            }
            for (auto &&k : li) {
                ans += cnt[k[0]][k[1]]*cnt[k[2]][k[3]];
            }
        }
    }
    cout << ans/2 << "\n";
    return 0;
}
